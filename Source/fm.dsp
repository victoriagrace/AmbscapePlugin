import("stdfaust.lib");
//import("oscillator.lib");
//freq = 440;
//amp = 0.1;
//
//car = 1;
//mod = 1;
//idx = 1;


fmosc(freq, amp, car, mod, idx) = c_osc
with {
m_osc = os.osc(freq * mod) * freq * mod * idx;
c_osc = os.osc(freq * car + m_osc) * amp;
};

pad(note, car, mod, indx) = 
fmosc(ba.midikey2hz(note), 0.3, car, mod, indx * 0.99 + (0.5 * lfomod)) +
fmosc(ba.midikey2hz(note + 0.1), 0.3, car, mod + 0.0001, indx + (2 * lfomod)) +
fmosc(ba.midikey2hz(note - 0.001), 0.3, car, mod - 0.0001, indx * 1.01 + (0.5 * lfomod))
with{
frq = ba.midikey2hz(note);
lfomod = (1 + os.osc(1.0/15.0)) * 0.5;
};

base = hslider("base", 69, 12, 100, 1): si.smoo;
mod=1;
car=1;
indx = hslider("indx", 1, 0, 20, 0.01): si.smoo;
//indx=1;
amp = hslider("amp", 0.3, 0, 1, 0.01): si.smoo;

lead_note = hslider("lead", 69, 12, 100, 1): si.smooth(ba.tau2pole(0.1));

my_lfo(freq) = 1 + os.osc(freq) * 0.5;

pull = hslider("pull", 0, 0, 1, 0.001) : si.smoo;
rot = hslider("rotation", 0, 0, 1, 0.001) : si.smoo;
xPos = hslider("xPos", 0, 0, 1, 0.001) : si.smoo;
yPos = hslider("yPos", 0, 0, 1, 0.001) : si.smoo;

scale(val, vmin, vmax) = val * (vmax - vmin) + vmin;

//lead = os.pulsetrain(ba.midikey2hz(74),0.25):fi.lowpass(2,2000);

gate_sig = checkbox("gate");
gate = gate_sig : si.smooth(ba.tau2pole(0.45));
gate_drones = gate_sig : si.smooth(ba.tau2pole(1.0));

note_1 = hslider("note_1", 11, 0, 12, 1) : si.smooth(ba.tau2pole(0.01));
note_2 = hslider("note_2", 0, -12, 12, 1) : si.smooth(ba.tau2pole(0.01));

vib = os.osc(6) * 0.1;

//lead = os.pulsetrain(ba.midikey2hz(lead_note + vib * rot), scale(pull,0.01,0.99)):fi.lowpass(2, scale(pull, 200, 3000)) * gate;
lead = os.osc(ba.midikey2hz(lead_note + vib * rot)):fi.lowpass(2, scale(1-pull, 200, 3000)) *pull*gate;

//scale(rot, 200, 3000)

//lead = pulsetrain((ba.midikey2hz(note + vib * rot))*lead_note,scale(pull,0.01,0.99)):fi.lowpass(2, scale(pull, 2000, 8000))  *gate;

//lead = os.pulsetrain(300,duty):fi.lowpass(2,fc);
//duty = hslider("amp", 0.1, 0.01, 0.99, 0.01): si.smoo;
//fc = hslider("amp", 400, 50, 100, 0.01): si.smoo;
//process = lead;

findex = indx + scale(pull, 0, 3);


//drones = (pad(base, car, mod, findex)  + 
//pad(base + 7, car, mod, findex) + 
//pad(base + note_1, car, mod, findex) + 
//pad(base + 2, car, mod, findex) + 
//pad(base -12, car, mod, indx)) * gate_drones * 0.4;

s = hslider("soprano", 69, 12, 100, 1): si.smoo;
a = hslider("alto", 69, 12, 100, 1): si.smoo;
t = hslider("tenor", 69, 12, 100, 1): si.smoo;
b = hslider("bass", 69, 12, 100, 1): si.smoo;

drones = (
pad(s, car, mod, findex)  + 
pad(a, car, mod, findex) + 
pad(t, car, mod, findex) + 
pad(b, car, mod, findex)) 

* gate_drones * ba.db2linear(-15);

process = hgroup("fm", drones + lead  <:_,_);
