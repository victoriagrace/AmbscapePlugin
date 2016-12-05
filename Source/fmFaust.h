//----------------------------------------------------------
//
// Code generated with Faust 0.9.92 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
#include <cmath>
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline int faustpower<0>(int x)            { return 1; }
template <> 	 inline int faustpower<1>(int x)            { return x; }
template <> 	 inline int faustpower<2>(int x)            { return x*x; }
template <int N> inline float faustpower(float x)            { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline float faustpower<0>(float x)          { return 1; }
template <> 	 inline float faustpower<1>(float x)          { return x; }
template <> 	 inline float faustpower<2>(float x)          { return x*x; }
#endif
// Music 256a / CS 476a | fall 2016
// CCRMA, Stanford University
//
// Author: Romain Michon (rmichonATccrmaDOTstanfordDOTedu)
// Description: Simple Faust architecture file to easily integrate a Faust DSP module
// in a JUCE project

// needed by any Faust arch file
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>

/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif

using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }

inline int int2pow2(int x)		{ int r = 0; while ((1<<r) < x) r++; return r; }

inline long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

inline bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

inline const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


// allows to control a Faust DSP module in a simple manner by using parameter's path
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_MAPUI_H
#define FAUST_MAPUI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#include <vector>
#include <map>
#include <string>

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    protected:
    
        UI* fUI;

    public:
    
        DecoratorUI(UI* ui = 0):fUI(ui)
        {}

        virtual ~DecoratorUI() { delete fUI; }

        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
            { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 	
            { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 			
            { fUI->addNumEntry(label, zone, init, min, max, step); }

        // -- passive widgets	
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
            { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
            { fUI->addVerticalBargraph(label, zone, min, max); }

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }

};

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/

#ifndef FAUST_PATHBUILDER_H
#define FAUST_PATHBUILDER_H

#include <vector>
#include <string>
#include <algorithm>

/*******************************************************************************
 * PathBuilder : Faust User Interface
 * Helper class to build complete hierarchical path for UI items.
 ******************************************************************************/

class PathBuilder
{

    protected:
    
        std::vector<std::string> fControlsLevel;
       
    public:
    
        PathBuilder() {}
        virtual ~PathBuilder() {}
    
        std::string buildPath(const std::string& label) 
        {
            std::string res = "/";
            for (size_t i = 0; i < fControlsLevel.size(); i++) {
                res += fControlsLevel[i];
                res += "/";
            }
            res += label;
            replace(res.begin(), res.end(), ' ', '_');
            return res;
        }
    
};

#endif  // FAUST_PATHBUILDER_H

/*******************************************************************************
 * MapUI : Faust User Interface
 * This class creates a map of complete hierarchical path and zones for each UI items.
 ******************************************************************************/

class MapUI : public UI, public PathBuilder
{
    
    protected:
    
        // Complete path map
        std::map<std::string, FAUSTFLOAT*> fPathZoneMap;
    
        // Label zone map
        std::map<std::string, FAUSTFLOAT*> fLabelZoneMap;
    
    public:
        
        MapUI() {};
        virtual ~MapUI() {};
        
        // -- widget's layouts
        void openTabBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openHorizontalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void openVerticalBox(const char* label)
        {
            fControlsLevel.push_back(label);
        }
        void closeBox()
        {
            fControlsLevel.pop_back();
        }
        
        // -- active widgets
        void addButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addCheckButton(const char* label, FAUSTFLOAT* zone)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT fmin, FAUSTFLOAT fmax, FAUSTFLOAT step)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- passive widgets
        void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT fmin, FAUSTFLOAT fmax)
        {
            fPathZoneMap[buildPath(label)] = zone;
            fLabelZoneMap[label] = zone;
        }
        
        // -- metadata declarations
        void declare(FAUSTFLOAT* zone, const char* key, const char* val)
        {}
        
        // set/get
        void setParamValue(const std::string& path, float value)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                *fPathZoneMap[path] = value;
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                *fLabelZoneMap[path] = value;
            }
        }
        
        float getParamValue(const std::string& path)
        {
            if (fPathZoneMap.find(path) != fPathZoneMap.end()) {
                return *fPathZoneMap[path];
            } else if (fLabelZoneMap.find(path) != fLabelZoneMap.end()) {
                return *fLabelZoneMap[path];
            } else {
                return 0.;
            }
        }
    
        // map access 
        std::map<std::string, FAUSTFLOAT*>& getMap() { return fPathZoneMap; }
        
        int getParamsCount() { return fPathZoneMap.size(); }
        
        std::string getParamAdress(int index) 
        { 
            std::map<std::string, FAUSTFLOAT*>::iterator it = fPathZoneMap.begin();
            while (index-- > 0 && it++ != fPathZoneMap.end()) {}
            return (*it).first;
        }
};

#endif // FAUST_MAPUI_H

// needed by any Faust arch file
/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;
struct Meta;

/**
* Signal processor definition.
*/

class dsp {

    public:

        dsp() {}
        virtual ~dsp() {}

        /* Return instance number of audio inputs */
        virtual int getNumInputs() = 0;
    
        /* Return instance number of audio outputs */
        virtual int getNumOutputs() = 0;
    
        /**
         * Trigger the UI* parameter with instance specific calls
         * to 'addBtton', 'addVerticalSlider'... in order to build the UI.
         *
         * @param ui_interface - the UI* user interface builder
         */
        virtual void buildUserInterface(UI* ui_interface) = 0;
    
        /* Returns the sample rate currently used by the instance */
        virtual int getSampleRate() = 0;
    
        /** Global init, calls the following methods :
         * - static class 'classInit' : static table initialisation
         * - 'instanceInit' : constants and instance table initialisation
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void init(int samplingRate) = 0;
    
        /** Init instance state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceInit(int samplingRate) = 0;
    
        /** Init instance constant state
         *
         * @param samplingRate - the sampling rate in Herz
         */
        virtual void instanceConstants(int samplingRate) = 0;
    
        /* Init default control parameters values */
        virtual void instanceResetUserInterface() = 0;
    
        /* Init instance state (delay lines...) */
        virtual void instanceClear() = 0;
    
        /**  
         * Return a clone of the instance.
         *
         * @return a copy of the instance on success, otherwise a null pointer.
         */
        virtual dsp* clone() = 0;
    
        /**
         * Trigger the Meta* parameter with instance specific calls to 'declare' (key, value metadata).
         *
         * @param m - the Meta* meta user
         */
        virtual void metadata(Meta* m) = 0;
    
        /**
         * DSP instance computation, to be called with sucessive in/out audio buffers.
         *
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         *
         */
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
    
        /**
         * DSP instance computation : alternative method to be used by subclasses.
         *
         * @param date_usec - the timestamp in microsec given by audio driver.
         * @param count - the nomber of frames to compute
         * @param inputs - the input audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         * @param outputs - the output audio buffers as an array of non-interleaved FAUSTFLOAT samples (eiher float, doucbe or quad)
         *
         */
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

/**
 * Generic DSP decorator.
 */

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual int getSampleRate() { return fDSP->getSampleRate(); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void instanceConstants(int samplingRate) { fDSP->instanceConstants(samplingRate); }
        virtual void instanceResetUserInterface() { fDSP->instanceResetUserInterface(); }
        virtual void instanceClear() { fDSP->instanceClear(); }
        virtual decorator_dsp* clone() { return new decorator_dsp(fDSP->clone()); }
        virtual void metadata(Meta* m) { return fDSP->metadata(m); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

/**
 * On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
 * flags to avoid costly denormals.
 */

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif

#ifndef __fmFaust__
#define __fmFaust__

// tags used by the Faust compiler to paste the generated c++ code
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS fmFaust
#endif

class fmFaust : public dsp {
  private:
	float 	fConst0;
	float 	fConst1;
	float 	fConst2;
	int 	iVec0[2];
	float 	fConst3;
	float 	fConst4;
	float 	fConst5;
	FAUSTFLOAT 	fslider0;
	float 	fRec2[2];
	float 	fConst6;
	float 	fConst7;
	float 	fConst8;
	float 	fRec3[2];
	float 	fConst9;
	float 	fRec4[2];
	FAUSTFLOAT 	fslider1;
	float 	fRec5[2];
	float 	fRec1[2];
	float 	fVec1[2];
	int 	IOTA;
	float 	fVec2[4096];
	FAUSTFLOAT 	fslider2;
	float 	fRec6[2];
	float 	fConst10;
	float 	fRec0[3];
	float 	fConst11;
	float 	fConst12;
	FAUSTFLOAT 	fcheckbox0;
	float 	fRec7[2];
	float 	fConst13;
	float 	fConst14;
	float 	fRec8[2];
	float 	fConst15;
	FAUSTFLOAT 	fslider3;
	float 	fRec11[2];
	float 	fConst16;
	float 	fConst17;
	float 	fConst18;
	float 	fRec12[2];
	float 	fConst19;
	float 	fRec13[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec14[2];
	float 	fConst20;
	float 	fRec15[2];
	float 	fRec16[2];
	float 	fRec9[2];
	float 	fRec10[2];
	float 	fConst21;
	float 	fRec19[2];
	float 	fRec20[2];
	float 	fRec17[2];
	float 	fRec18[2];
	float 	fConst22;
	FAUSTFLOAT 	fslider5;
	float 	fRec23[2];
	float 	fRec24[2];
	float 	fRec25[2];
	float 	fRec21[2];
	float 	fRec22[2];
	float 	fRec28[2];
	float 	fRec29[2];
	float 	fRec26[2];
	float 	fRec27[2];
	float 	fRec32[2];
	float 	fRec33[2];
	float 	fRec30[2];
	float 	fRec31[2];
	FAUSTFLOAT 	fslider6;
	float 	fRec36[2];
	float 	fRec37[2];
	float 	fRec38[2];
	float 	fRec34[2];
	float 	fRec35[2];
	float 	fRec41[2];
	float 	fRec42[2];
	float 	fRec39[2];
	float 	fRec40[2];
	float 	fRec45[2];
	float 	fRec46[2];
	float 	fRec43[2];
	float 	fRec44[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec49[2];
	float 	fRec50[2];
	float 	fRec51[2];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec54[2];
	float 	fRec55[2];
	float 	fRec52[2];
	float 	fRec53[2];
	float 	fRec58[2];
	float 	fRec59[2];
	float 	fRec56[2];
	float 	fRec57[2];
	float 	fRec62[2];
	float 	fRec63[2];
	float 	fRec60[2];
	float 	fRec61[2];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
		m->declare("miscoscillator.lib/name", "Faust Oscillator Library");
		m->declare("miscoscillator.lib/version", "0.0");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05f, max(1.0f, (float)fSamplingFreq));
		fConst1 = float(fConst0);
		fConst2 = (0.25f * fConst1);
		fConst3 = (1.0f / fConst0);
		fConst4 = expf((0 - (1e+01f / fConst0)));
		fConst5 = (1.0f - fConst4);
		fConst6 = (37.699112f / fConst0);
		fConst7 = sinf(fConst6);
		fConst8 = cosf(fConst6);
		fConst9 = (0 - fConst7);
		fConst10 = (3.1415927f / fConst0);
		fConst11 = expf((0 - (2.2222223f / fConst0)));
		fConst12 = (1.0f - fConst11);
		fConst13 = expf((0 - fConst3));
		fConst14 = (1.0f - fConst13);
		fConst15 = (6.2831855f / fConst0);
		fConst16 = (0.41887903f / fConst0);
		fConst17 = sinf(fConst16);
		fConst18 = cosf(fConst16);
		fConst19 = (0 - fConst17);
		fConst20 = (2764.3252f / fConst0);
		fConst21 = (2764.878f / fConst0);
		fConst22 = (2764.6016f / fConst0);
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 69.0f;
		fslider1 = 0.0f;
		fslider2 = 0.0f;
		fcheckbox0 = 0.0;
		fslider3 = 69.0f;
		fslider4 = 1.0f;
		fslider5 = 69.0f;
		fslider6 = 69.0f;
		fslider7 = 69.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		IOTA = 0;
		for (int i=0; i<4096; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	virtual fmFaust* clone() {
		return new fmFaust();
	}
	virtual int getSampleRate() {
		return fSamplingFreq;
	}
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openHorizontalBox("fm");
		ui_interface->addHorizontalSlider("alto", &fslider6, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("bass", &fslider3, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addCheckButton("gate", &fcheckbox0);
		ui_interface->addHorizontalSlider("indx", &fslider4, 1.0f, 0.0f, 2e+01f, 0.01f);
		ui_interface->addHorizontalSlider("lead", &fslider0, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("pull", &fslider2, 0.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->addHorizontalSlider("rotation", &fslider1, 0.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->addHorizontalSlider("soprano", &fslider5, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("tenor", &fslider7, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = (fConst5 * float(fslider0));
		float 	fSlow1 = (0.001f * float(fslider1));
		float 	fSlow2 = (0.001f * float(fslider2));
		float 	fSlow3 = float(fcheckbox0);
		float 	fSlow4 = (fConst12 * fSlow3);
		float 	fSlow5 = (fConst14 * fSlow3);
		float 	fSlow6 = (0.001f * float(fslider3));
		float 	fSlow7 = (0.001f * float(fslider4));
		float 	fSlow8 = (0.001f * float(fslider5));
		float 	fSlow9 = (0.001f * float(fslider6));
		float 	fSlow10 = (0.001f * float(fslider7));
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			fRec2[0] = (fSlow0 + (fConst4 * fRec2[1]));
			fRec3[0] = ((fConst7 * fRec4[1]) + (fConst8 * fRec3[1]));
			int iTemp0 = (1 - iVec0[1]);
			fRec4[0] = (((fConst8 * fRec4[1]) + (fConst9 * fRec3[1])) + iTemp0);
			fRec5[0] = (fSlow1 + (0.999f * fRec5[1]));
			float fTemp1 = max((4.4e+02f * powf(2.0f,(0.083333336f * ((fRec2[0] + (0.1f * (fRec3[0] * fRec5[0]))) + -69.0f)))), 23.44895f);
			float fTemp2 = max(2e+01f, fabsf(fTemp1));
			float fTemp3 = (fRec1[1] + (fConst3 * fTemp2));
			fRec1[0] = (fTemp3 - floorf(fTemp3));
			float fTemp4 = faustpower<2>(((2 * fRec1[0]) + -1));
			fVec1[0] = fTemp4;
			float fTemp5 = ((iVec0[1] * (fVec1[0] - fVec1[1])) / fTemp2);
			fVec2[IOTA&4095] = fTemp5;
			fRec6[0] = (fSlow2 + (0.999f * fRec6[1]));
			float fTemp6 = max((float)0, min((float)2047, (fConst1 * (((0.98f * fRec6[0]) + 0.01f) / fTemp1))));
			int iTemp7 = int(fTemp6);
			float fTemp8 = floorf(fTemp6);
			float fTemp9 = tanf((fConst10 * ((2800 * fRec5[0]) + 200)));
			float fTemp10 = (1.0f / fTemp9);
			float fTemp11 = (((fTemp10 + 1.4142135f) / fTemp9) + 1);
			fRec0[0] = ((fConst2 * (fVec2[IOTA&4095] - ((fVec2[(IOTA-iTemp7)&4095] * (fTemp8 + (1 - fTemp6))) + ((fTemp6 - fTemp8) * fVec2[(IOTA-int((iTemp7 + 1)))&4095])))) - (((fRec0[2] * (((fTemp10 + -1.4142135f) / fTemp9) + 1)) + (2 * (fRec0[1] * (1 - (1.0f / faustpower<2>(fTemp9)))))) / fTemp11));
			fRec7[0] = (fSlow4 + (fConst11 * fRec7[1]));
			fRec8[0] = (fSlow5 + (fConst13 * fRec8[1]));
			fRec11[0] = (fSlow6 + (0.999f * fRec11[1]));
			float fTemp12 = powf(2.0f,(0.083333336f * (fRec11[0] + -69.001f)));
			fRec12[0] = ((fConst17 * fRec13[1]) + (fConst18 * fRec12[1]));
			fRec13[0] = (((fConst18 * fRec13[1]) + (fConst19 * fRec12[1])) + iTemp0);
			float fTemp13 = (0.25f * (fRec12[0] + 1));
			fRec14[0] = (fSlow7 + (0.999f * fRec14[1]));
			float fTemp14 = (3 * fRec6[0]);
			float fTemp15 = (fRec14[0] + fTemp14);
			float fTemp16 = (fTemp13 + (1.01f * fTemp15));
			float fTemp17 = (fConst20 * fTemp12);
			float fTemp18 = sinf(fTemp17);
			float fTemp19 = cosf(fTemp17);
			fRec15[0] = ((fRec16[1] * fTemp18) + (fRec15[1] * fTemp19));
			fRec16[0] = (((fRec16[1] * fTemp19) + (fRec15[1] * (0 - fTemp18))) + iTemp0);
			float fTemp20 = (fConst15 * (fTemp12 * ((439.956f * (fTemp16 * fRec15[0])) + 4.4e+02f)));
			float fTemp21 = sinf(fTemp20);
			float fTemp22 = cosf(fTemp20);
			fRec9[0] = ((fRec10[1] * fTemp21) + (fRec9[1] * fTemp22));
			fRec10[0] = (((fRec10[1] * fTemp22) + (fRec9[1] * (0 - fTemp21))) + iTemp0);
			float fTemp23 = powf(2.0f,(0.083333336f * (fRec11[0] + -68.9f)));
			float fTemp24 = ((fTemp14 + (fRec12[0] + fRec14[0])) + 1);
			float fTemp25 = (fConst21 * fTemp23);
			float fTemp26 = sinf(fTemp25);
			float fTemp27 = cosf(fTemp25);
			fRec19[0] = ((fRec20[1] * fTemp26) + (fRec19[1] * fTemp27));
			fRec20[0] = (((fRec20[1] * fTemp27) + (fRec19[1] * (0 - fTemp26))) + iTemp0);
			float fTemp28 = (fConst15 * (fTemp23 * ((440.044f * (fTemp24 * fRec19[0])) + 4.4e+02f)));
			float fTemp29 = sinf(fTemp28);
			float fTemp30 = cosf(fTemp28);
			fRec17[0] = ((fRec18[1] * fTemp29) + (fRec17[1] * fTemp30));
			fRec18[0] = (((fRec18[1] * fTemp30) + (fRec17[1] * (0 - fTemp29))) + iTemp0);
			fRec23[0] = (fSlow8 + (0.999f * fRec23[1]));
			float fTemp31 = powf(2.0f,(0.083333336f * (fRec23[0] + -69.0f)));
			float fTemp32 = (fConst22 * fTemp31);
			float fTemp33 = sinf(fTemp32);
			float fTemp34 = cosf(fTemp32);
			fRec24[0] = ((fRec25[1] * fTemp33) + (fRec24[1] * fTemp34));
			fRec25[0] = (((fRec25[1] * fTemp34) + (fRec24[1] * (0 - fTemp33))) + iTemp0);
			float fTemp35 = (fTemp13 + (0.99f * fTemp15));
			float fTemp36 = (fConst22 * (fTemp31 * ((fRec24[0] * fTemp35) + 1.0f)));
			float fTemp37 = sinf(fTemp36);
			float fTemp38 = cosf(fTemp36);
			fRec21[0] = ((fRec22[1] * fTemp37) + (fRec21[1] * fTemp38));
			fRec22[0] = (((fRec22[1] * fTemp38) + (fRec21[1] * (0 - fTemp37))) + iTemp0);
			float fTemp39 = powf(2.0f,(0.083333336f * (fRec23[0] + -68.9f)));
			float fTemp40 = (fConst21 * fTemp39);
			float fTemp41 = sinf(fTemp40);
			float fTemp42 = cosf(fTemp40);
			fRec28[0] = ((fRec29[1] * fTemp41) + (fRec28[1] * fTemp42));
			fRec29[0] = (((fRec29[1] * fTemp42) + (fRec28[1] * (0 - fTemp41))) + iTemp0);
			float fTemp43 = (fConst15 * (fTemp39 * ((440.044f * (fRec28[0] * fTemp24)) + 4.4e+02f)));
			float fTemp44 = sinf(fTemp43);
			float fTemp45 = cosf(fTemp43);
			fRec26[0] = ((fRec27[1] * fTemp44) + (fRec26[1] * fTemp45));
			fRec27[0] = (((fRec27[1] * fTemp45) + (fRec26[1] * (0 - fTemp44))) + iTemp0);
			float fTemp46 = powf(2.0f,(0.083333336f * (fRec23[0] + -69.001f)));
			float fTemp47 = (fConst20 * fTemp46);
			float fTemp48 = sinf(fTemp47);
			float fTemp49 = cosf(fTemp47);
			fRec32[0] = ((fRec33[1] * fTemp48) + (fRec32[1] * fTemp49));
			fRec33[0] = (((fRec33[1] * fTemp49) + (fRec32[1] * (0 - fTemp48))) + iTemp0);
			float fTemp50 = (fConst15 * (fTemp46 * ((439.956f * (fRec32[0] * fTemp16)) + 4.4e+02f)));
			float fTemp51 = sinf(fTemp50);
			float fTemp52 = cosf(fTemp50);
			fRec30[0] = ((fRec31[1] * fTemp51) + (fRec30[1] * fTemp52));
			fRec31[0] = (((fRec31[1] * fTemp52) + (fRec30[1] * (0 - fTemp51))) + iTemp0);
			fRec36[0] = (fSlow9 + (0.999f * fRec36[1]));
			float fTemp53 = powf(2.0f,(0.083333336f * (fRec36[0] + -69.0f)));
			float fTemp54 = (fConst22 * fTemp53);
			float fTemp55 = sinf(fTemp54);
			float fTemp56 = cosf(fTemp54);
			fRec37[0] = ((fRec38[1] * fTemp55) + (fRec37[1] * fTemp56));
			fRec38[0] = (((fRec38[1] * fTemp56) + (fRec37[1] * (0 - fTemp55))) + iTemp0);
			float fTemp57 = (fConst22 * (fTemp53 * ((fTemp35 * fRec37[0]) + 1.0f)));
			float fTemp58 = sinf(fTemp57);
			float fTemp59 = cosf(fTemp57);
			fRec34[0] = ((fRec35[1] * fTemp58) + (fRec34[1] * fTemp59));
			fRec35[0] = (((fRec35[1] * fTemp59) + (fRec34[1] * (0 - fTemp58))) + iTemp0);
			float fTemp60 = powf(2.0f,(0.083333336f * (fRec36[0] + -68.9f)));
			float fTemp61 = (fConst21 * fTemp60);
			float fTemp62 = sinf(fTemp61);
			float fTemp63 = cosf(fTemp61);
			fRec41[0] = ((fRec42[1] * fTemp62) + (fRec41[1] * fTemp63));
			fRec42[0] = (((fRec42[1] * fTemp63) + (fRec41[1] * (0 - fTemp62))) + iTemp0);
			float fTemp64 = (fConst15 * (fTemp60 * ((440.044f * (fTemp24 * fRec41[0])) + 4.4e+02f)));
			float fTemp65 = sinf(fTemp64);
			float fTemp66 = cosf(fTemp64);
			fRec39[0] = ((fRec40[1] * fTemp65) + (fRec39[1] * fTemp66));
			fRec40[0] = (((fRec40[1] * fTemp66) + (fRec39[1] * (0 - fTemp65))) + iTemp0);
			float fTemp67 = powf(2.0f,(0.083333336f * (fRec36[0] + -69.001f)));
			float fTemp68 = (fConst20 * fTemp67);
			float fTemp69 = sinf(fTemp68);
			float fTemp70 = cosf(fTemp68);
			fRec45[0] = ((fRec46[1] * fTemp69) + (fRec45[1] * fTemp70));
			fRec46[0] = (((fRec46[1] * fTemp70) + (fRec45[1] * (0 - fTemp69))) + iTemp0);
			float fTemp71 = (fConst15 * (fTemp67 * ((439.956f * (fTemp16 * fRec45[0])) + 4.4e+02f)));
			float fTemp72 = sinf(fTemp71);
			float fTemp73 = cosf(fTemp71);
			fRec43[0] = ((fRec44[1] * fTemp72) + (fRec43[1] * fTemp73));
			fRec44[0] = (((fRec44[1] * fTemp73) + (fRec43[1] * (0 - fTemp72))) + iTemp0);
			fRec49[0] = (fSlow10 + (0.999f * fRec49[1]));
			float fTemp74 = powf(2.0f,(0.083333336f * (fRec49[0] + -69.0f)));
			float fTemp75 = (fConst22 * fTemp74);
			float fTemp76 = sinf(fTemp75);
			float fTemp77 = cosf(fTemp75);
			fRec50[0] = ((fRec51[1] * fTemp76) + (fRec50[1] * fTemp77));
			fRec51[0] = (((fRec51[1] * fTemp77) + (fRec50[1] * (0 - fTemp76))) + iTemp0);
			float fTemp78 = (fConst22 * (fTemp74 * ((fTemp35 * fRec50[0]) + 1.0f)));
			float fTemp79 = sinf(fTemp78);
			float fTemp80 = cosf(fTemp78);
			fRec47[0] = ((fRec48[1] * fTemp79) + (fRec47[1] * fTemp80));
			fRec48[0] = (((fRec48[1] * fTemp80) + (fRec47[1] * (0 - fTemp79))) + iTemp0);
			float fTemp81 = powf(2.0f,(0.083333336f * (fRec49[0] + -68.9f)));
			float fTemp82 = (fConst21 * fTemp81);
			float fTemp83 = sinf(fTemp82);
			float fTemp84 = cosf(fTemp82);
			fRec54[0] = ((fRec55[1] * fTemp83) + (fRec54[1] * fTemp84));
			fRec55[0] = (((fRec55[1] * fTemp84) + (fRec54[1] * (0 - fTemp83))) + iTemp0);
			float fTemp85 = (fConst15 * (fTemp81 * ((440.044f * (fTemp24 * fRec54[0])) + 4.4e+02f)));
			float fTemp86 = sinf(fTemp85);
			float fTemp87 = cosf(fTemp85);
			fRec52[0] = ((fRec53[1] * fTemp86) + (fRec52[1] * fTemp87));
			fRec53[0] = (((fRec53[1] * fTemp87) + (fRec52[1] * (0 - fTemp86))) + iTemp0);
			float fTemp88 = powf(2.0f,(0.083333336f * (fRec49[0] + -69.001f)));
			float fTemp89 = (fConst20 * fTemp88);
			float fTemp90 = sinf(fTemp89);
			float fTemp91 = cosf(fTemp89);
			fRec58[0] = ((fRec59[1] * fTemp90) + (fRec58[1] * fTemp91));
			fRec59[0] = (((fRec59[1] * fTemp91) + (fRec58[1] * (0 - fTemp90))) + iTemp0);
			float fTemp92 = (fConst15 * (fTemp88 * ((439.956f * (fTemp16 * fRec58[0])) + 4.4e+02f)));
			float fTemp93 = sinf(fTemp92);
			float fTemp94 = cosf(fTemp92);
			fRec56[0] = ((fRec57[1] * fTemp93) + (fRec56[1] * fTemp94));
			fRec57[0] = (((fRec57[1] * fTemp94) + (fRec56[1] * (0 - fTemp93))) + iTemp0);
			float fTemp95 = powf(2.0f,(0.083333336f * (fRec11[0] + -69.0f)));
			float fTemp96 = (fConst22 * fTemp95);
			float fTemp97 = sinf(fTemp96);
			float fTemp98 = cosf(fTemp96);
			fRec62[0] = ((fRec63[1] * fTemp97) + (fRec62[1] * fTemp98));
			fRec63[0] = (((fRec63[1] * fTemp98) + (fRec62[1] * (0 - fTemp97))) + iTemp0);
			float fTemp99 = (fConst22 * (fTemp95 * ((fTemp35 * fRec62[0]) + 1.0f)));
			float fTemp100 = sinf(fTemp99);
			float fTemp101 = cosf(fTemp99);
			fRec60[0] = ((fRec61[1] * fTemp100) + (fRec60[1] * fTemp101));
			fRec61[0] = (((fRec61[1] * fTemp101) + (fRec60[1] * (0 - fTemp100))) + iTemp0);
			float fTemp102 = (((((fRec0[2] + (2.0f * fRec0[1])) + fRec0[0]) * fRec7[0]) / fTemp11) + (0.05334838f * (fRec8[0] * (fRec9[0] + (fRec17[0] + (((((((((fRec21[0] + fRec26[0]) + fRec30[0]) + fRec34[0]) + fRec39[0]) + fRec43[0]) + fRec47[0]) + fRec52[0]) + fRec56[0]) + fRec60[0]))))));
			output0[i] = (FAUSTFLOAT)fTemp102;
			output1[i] = (FAUSTFLOAT)fTemp102;
			// post processing
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec6[1] = fRec6[0];
			IOTA = IOTA+1;
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			iVec0[1] = iVec0[0];
		}
	}
};


#endif
