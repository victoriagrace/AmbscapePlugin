import("stdfaust.lib");
import("oscillator.lib");
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
fmosc(ba.midikey2hz(note), 0.3, car, mod, indx * 0.99) +
fmosc(ba.midikey2hz(note + 0.1), 0.3, car, mod + 0.0001, indx) +
fmosc(ba.midikey2hz(note - 0.001), 0.3, car, mod - 0.0001, indx * 1.01)
with{
frq = ba.midikey2hz(note);
};

note = hslider("freq", 69, 12, 100, 1): si.smoo;
//car = hslider("car", 1, 0, 20, 0.01): si.smoo;
//mod = hslider("mod", 1, 0, 20, 0.01): si.smoo;
mod=1;
car=1;
//indx = hslider("indx", 1, 0, 20, 0.01): si.smoo;
indx=1;
amp = hslider("amp", 0.3, 0, 1, 0.01): si.smoo;

lead_note = hslider("lead", 69, 12, 100, 1): si.smooth(ba.tau2pole(0.1));

my_lfo(freq) = 1 + osc(freq) * 0.5;

pull = hslider("pull", 0, 0, 1, 0.001) : si.smoo;
rot = hslider("rotation", 0, 0, 1, 0.001) : si.smoo;
xPos = hslider("xPos", 0, 0, 1, 0.001) : si.smoo;
yPos = hslider("yPos", 0, 0, 1, 0.001) : si.smoo;

scale(val, vmin, vmax) = val * (vmax - vmin) + vmin;

//lead = os.pulsetrain(ba.midikey2hz(74),0.25):fi.lowpass(2,2000);

gate = checkbox("gate") : si.smooth(ba.tau2pole(0.45));


vib = os.osc(6) * 0.1;

lead = pulsetrain(ba.midikey2hz(lead_note + vib * rot),scale(pull,0.01,0.99)):fi.lowpass(2, scale(pull, 2000, 8000)) * gate;

//lead = os.pulsetrain(300,duty):fi.lowpass(2,fc);
//duty = hslider("amp", 0.1, 0.01, 0.99, 0.01): si.smoo;
//fc = hslider("amp", 400, 50, 100, 0.01): si.smoo;
//process = lead;

findex = indx + scale(pull, 0, 1.5);

process = hgroup("fm", pad(note, car, mod, findex)  + 
pad(note + 7, car, mod, findex) + 
pad(note + 11, car, mod, findex)+ 
pad(note + 2, car, mod, findex) + 
pad(note -12, car, mod, indx) + lead <:_,_);

