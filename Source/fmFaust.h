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
	FAUSTFLOAT 	fcheckbox0;
	int 	iVec0[2];
	float 	fRec0[2];
	float 	fConst3;
	FAUSTFLOAT 	fslider0;
	float 	fRec3[2];
	float 	fConst4;
	float 	fRec4[2];
	float 	fRec5[2];
	FAUSTFLOAT 	fslider1;
	float 	fRec6[2];
	FAUSTFLOAT 	fslider2;
	float 	fRec7[2];
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fRec8[2];
	float 	fConst8;
	float 	fRec9[2];
	float 	fRec1[2];
	float 	fRec2[2];
	float 	fConst9;
	float 	fRec12[2];
	float 	fRec13[2];
	float 	fRec10[2];
	float 	fRec11[2];
	float 	fConst10;
	float 	fRec16[2];
	float 	fRec17[2];
	float 	fRec14[2];
	float 	fRec15[2];
	FAUSTFLOAT 	fslider3;
	float 	fRec20[2];
	float 	fRec21[2];
	float 	fRec22[2];
	float 	fRec18[2];
	float 	fRec19[2];
	float 	fRec25[2];
	float 	fRec26[2];
	float 	fRec23[2];
	float 	fRec24[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec29[2];
	float 	fRec30[2];
	float 	fRec31[2];
	float 	fRec27[2];
	float 	fRec28[2];
	float 	fRec34[2];
	float 	fRec35[2];
	float 	fRec32[2];
	float 	fRec33[2];
	float 	fRec38[2];
	float 	fRec39[2];
	float 	fRec36[2];
	float 	fRec37[2];
	FAUSTFLOAT 	fslider5;
	float 	fRec42[2];
	float 	fRec43[2];
	float 	fRec44[2];
	float 	fRec40[2];
	float 	fRec41[2];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec45[2];
	float 	fRec46[2];
	float 	fRec51[2];
	float 	fRec52[2];
	float 	fRec49[2];
	float 	fRec50[2];
	float 	fRec55[2];
	float 	fRec56[2];
	float 	fRec53[2];
	float 	fRec54[2];
	float 	fConst11;
	float 	fConst12;
	float 	fRec57[2];
	float 	fConst13;
	float 	fConst14;
	FAUSTFLOAT 	fslider6;
	float 	fRec61[2];
	float 	fConst15;
	float 	fConst16;
	float 	fConst17;
	float 	fRec62[2];
	float 	fConst18;
	float 	fRec63[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec64[2];
	float 	fRec59[2];
	float 	fRec60[2];
	float 	fConst19;
	float 	fRec58[3];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("miscoscillator.lib/name", "Faust Oscillator Library");
		m->declare("miscoscillator.lib/version", "0.0");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05f, max(1.0f, (float)fSamplingFreq));
		fConst1 = expf((0 - (1.0f / fConst0)));
		fConst2 = (1.0f - fConst1);
		fConst3 = (6.2831855f / fConst0);
		fConst4 = (2764.3252f / fConst0);
		fConst5 = (0.41887903f / fConst0);
		fConst6 = sinf(fConst5);
		fConst7 = cosf(fConst5);
		fConst8 = (0 - fConst6);
		fConst9 = (2764.878f / fConst0);
		fConst10 = (2764.6016f / fConst0);
		fConst11 = expf((0 - (2.2222223f / fConst0)));
		fConst12 = (1.0f - fConst11);
		fConst13 = expf((0 - (1e+01f / fConst0)));
		fConst14 = (1.0f - fConst13);
		fConst15 = (37.699112f / fConst0);
		fConst16 = sinf(fConst15);
		fConst17 = cosf(fConst15);
		fConst18 = (0 - fConst16);
		fConst19 = (3.1415927f / fConst0);
	}
	virtual void instanceResetUserInterface() {
		fcheckbox0 = 0.0;
		fslider0 = 69.0f;
		fslider1 = 1.0f;
		fslider2 = 0.0f;
		fslider3 = 69.0f;
		fslider4 = 69.0f;
		fslider5 = 69.0f;
		fslider6 = 69.0f;
		fslider7 = 0.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<3; i++) fRec58[i] = 0;
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
		ui_interface->addHorizontalSlider("alto", &fslider5, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("bass", &fslider0, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addCheckButton("gate", &fcheckbox0);
		ui_interface->addHorizontalSlider("indx", &fslider1, 1.0f, 0.0f, 2e+01f, 0.01f);
		ui_interface->addHorizontalSlider("lead", &fslider6, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("pull", &fslider2, 0.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->addHorizontalSlider("rotation", &fslider7, 0.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->addHorizontalSlider("soprano", &fslider3, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("tenor", &fslider4, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = float(fcheckbox0);
		float 	fSlow1 = (fConst2 * fSlow0);
		float 	fSlow2 = (0.001f * float(fslider0));
		float 	fSlow3 = (0.001f * float(fslider1));
		float 	fSlow4 = (0.001f * float(fslider2));
		float 	fSlow5 = (0.001f * float(fslider3));
		float 	fSlow6 = (0.001f * float(fslider4));
		float 	fSlow7 = (0.001f * float(fslider5));
		float 	fSlow8 = (fConst12 * fSlow0);
		float 	fSlow9 = (fConst14 * float(fslider6));
		float 	fSlow10 = (0.001f * float(fslider7));
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			fRec0[0] = (fSlow1 + (fConst1 * fRec0[1]));
			fRec3[0] = (fSlow2 + (0.999f * fRec3[1]));
			float fTemp0 = powf(2.0f,(0.083333336f * (fRec3[0] + -69.001f)));
			float fTemp1 = (fConst4 * fTemp0);
			float fTemp2 = sinf(fTemp1);
			float fTemp3 = cosf(fTemp1);
			fRec4[0] = ((fRec5[1] * fTemp2) + (fRec4[1] * fTemp3));
			int iTemp4 = (1 - iVec0[1]);
			fRec5[0] = (((fRec5[1] * fTemp3) + (fRec4[1] * (0 - fTemp2))) + iTemp4);
			fRec6[0] = (fSlow3 + (0.999f * fRec6[1]));
			fRec7[0] = (fSlow4 + (0.999f * fRec7[1]));
			float fTemp5 = (fRec6[0] + (3 * fRec7[0]));
			fRec8[0] = ((fConst6 * fRec9[1]) + (fConst7 * fRec8[1]));
			fRec9[0] = (((fConst7 * fRec9[1]) + (fConst8 * fRec8[1])) + iTemp4);
			float fTemp6 = (0.25f * (fRec8[0] + 1));
			float fTemp7 = ((1.01f * fTemp5) + fTemp6);
			float fTemp8 = (fConst3 * (fTemp0 * ((439.956f * (fRec4[0] * fTemp7)) + 4.4e+02f)));
			float fTemp9 = sinf(fTemp8);
			float fTemp10 = cosf(fTemp8);
			fRec1[0] = ((fRec2[1] * fTemp9) + (fRec1[1] * fTemp10));
			fRec2[0] = (((fRec1[1] * (0 - fTemp9)) + (fRec2[1] * fTemp10)) + iTemp4);
			float fTemp11 = powf(2.0f,(0.083333336f * (fRec3[0] + -68.9f)));
			float fTemp12 = ((fTemp5 + fRec8[0]) + 1);
			float fTemp13 = (fConst9 * fTemp11);
			float fTemp14 = cosf(fTemp13);
			float fTemp15 = sinf(fTemp13);
			fRec12[0] = ((fRec12[1] * fTemp14) + (fRec13[1] * fTemp15));
			fRec13[0] = (((fRec12[1] * (0 - fTemp15)) + (fRec13[1] * fTemp14)) + iTemp4);
			float fTemp16 = (fConst3 * (fTemp11 * ((440.044f * (fTemp12 * fRec12[0])) + 4.4e+02f)));
			float fTemp17 = sinf(fTemp16);
			float fTemp18 = cosf(fTemp16);
			fRec10[0] = ((fRec11[1] * fTemp17) + (fRec10[1] * fTemp18));
			fRec11[0] = (((fRec11[1] * fTemp18) + (fRec10[1] * (0 - fTemp17))) + iTemp4);
			float fTemp19 = powf(2.0f,(0.083333336f * (fRec3[0] + -69.0f)));
			float fTemp20 = ((0.99f * fTemp5) + fTemp6);
			float fTemp21 = (fConst10 * fTemp19);
			float fTemp22 = cosf(fTemp21);
			float fTemp23 = sinf(fTemp21);
			fRec16[0] = ((fRec16[1] * fTemp22) + (fRec17[1] * fTemp23));
			fRec17[0] = (((fRec16[1] * (0 - fTemp23)) + (fRec17[1] * fTemp22)) + iTemp4);
			float fTemp24 = (fConst10 * (fTemp19 * ((fTemp20 * fRec16[0]) + 1.0f)));
			float fTemp25 = sinf(fTemp24);
			float fTemp26 = cosf(fTemp24);
			fRec14[0] = ((fRec15[1] * fTemp25) + (fRec14[1] * fTemp26));
			fRec15[0] = (((fRec15[1] * fTemp26) + (fRec14[1] * (0 - fTemp25))) + iTemp4);
			fRec20[0] = (fSlow5 + (0.999f * fRec20[1]));
			float fTemp27 = powf(2.0f,(0.083333336f * (fRec20[0] + -68.9f)));
			float fTemp28 = (fConst9 * fTemp27);
			float fTemp29 = cosf(fTemp28);
			float fTemp30 = sinf(fTemp28);
			fRec21[0] = ((fRec21[1] * fTemp29) + (fRec22[1] * fTemp30));
			fRec22[0] = (((fRec21[1] * (0 - fTemp30)) + (fRec22[1] * fTemp29)) + iTemp4);
			float fTemp31 = (fConst3 * (fTemp27 * ((440.044f * (fRec21[0] * fTemp12)) + 4.4e+02f)));
			float fTemp32 = sinf(fTemp31);
			float fTemp33 = cosf(fTemp31);
			fRec18[0] = ((fRec19[1] * fTemp32) + (fRec18[1] * fTemp33));
			fRec19[0] = (((fRec19[1] * fTemp33) + (fRec18[1] * (0 - fTemp32))) + iTemp4);
			float fTemp34 = powf(2.0f,(0.083333336f * (fRec20[0] + -69.0f)));
			float fTemp35 = (fConst10 * fTemp34);
			float fTemp36 = cosf(fTemp35);
			float fTemp37 = sinf(fTemp35);
			fRec25[0] = ((fRec25[1] * fTemp36) + (fRec26[1] * fTemp37));
			fRec26[0] = (((fRec25[1] * (0 - fTemp37)) + (fRec26[1] * fTemp36)) + iTemp4);
			float fTemp38 = (fConst10 * (fTemp34 * ((fRec25[0] * fTemp20) + 1.0f)));
			float fTemp39 = cosf(fTemp38);
			float fTemp40 = sinf(fTemp38);
			fRec23[0] = ((fRec23[1] * fTemp39) + (fRec24[1] * fTemp40));
			fRec24[0] = (((fRec23[1] * (0 - fTemp40)) + (fRec24[1] * fTemp39)) + iTemp4);
			fRec29[0] = (fSlow6 + (0.999f * fRec29[1]));
			float fTemp41 = powf(2.0f,(0.083333336f * (fRec29[0] + -69.001f)));
			float fTemp42 = (fConst4 * fTemp41);
			float fTemp43 = sinf(fTemp42);
			float fTemp44 = cosf(fTemp42);
			fRec30[0] = ((fRec31[1] * fTemp43) + (fRec30[1] * fTemp44));
			fRec31[0] = (((fRec31[1] * fTemp44) + (fRec30[1] * (0 - fTemp43))) + iTemp4);
			float fTemp45 = (fConst3 * (fTemp41 * ((439.956f * (fRec30[0] * fTemp7)) + 4.4e+02f)));
			float fTemp46 = sinf(fTemp45);
			float fTemp47 = cosf(fTemp45);
			fRec27[0] = ((fRec28[1] * fTemp46) + (fRec27[1] * fTemp47));
			fRec28[0] = (((fRec27[1] * (0 - fTemp46)) + (fRec28[1] * fTemp47)) + iTemp4);
			float fTemp48 = powf(2.0f,(0.083333336f * (fRec29[0] + -68.9f)));
			float fTemp49 = (fConst9 * fTemp48);
			float fTemp50 = sinf(fTemp49);
			float fTemp51 = cosf(fTemp49);
			fRec34[0] = ((fRec35[1] * fTemp50) + (fRec34[1] * fTemp51));
			fRec35[0] = (((fRec35[1] * fTemp51) + (fRec34[1] * (0 - fTemp50))) + iTemp4);
			float fTemp52 = (fConst3 * (fTemp48 * ((440.044f * (fRec34[0] * fTemp12)) + 4.4e+02f)));
			float fTemp53 = sinf(fTemp52);
			float fTemp54 = cosf(fTemp52);
			fRec32[0] = ((fRec33[1] * fTemp53) + (fRec32[1] * fTemp54));
			fRec33[0] = (((fRec32[1] * (0 - fTemp53)) + (fRec33[1] * fTemp54)) + iTemp4);
			float fTemp55 = powf(2.0f,(0.083333336f * (fRec29[0] + -69.0f)));
			float fTemp56 = (fConst10 * fTemp55);
			float fTemp57 = sinf(fTemp56);
			float fTemp58 = cosf(fTemp56);
			fRec38[0] = ((fRec39[1] * fTemp57) + (fRec38[1] * fTemp58));
			fRec39[0] = (((fRec39[1] * fTemp58) + (fRec38[1] * (0 - fTemp57))) + iTemp4);
			float fTemp59 = (fConst10 * (fTemp55 * ((fRec38[0] * fTemp20) + 1.0f)));
			float fTemp60 = sinf(fTemp59);
			float fTemp61 = cosf(fTemp59);
			fRec36[0] = ((fRec37[1] * fTemp60) + (fRec36[1] * fTemp61));
			fRec37[0] = (((fRec36[1] * (0 - fTemp60)) + (fRec37[1] * fTemp61)) + iTemp4);
			fRec42[0] = (fSlow7 + (0.999f * fRec42[1]));
			float fTemp62 = powf(2.0f,(0.083333336f * (fRec42[0] + -69.001f)));
			float fTemp63 = (fConst4 * fTemp62);
			float fTemp64 = sinf(fTemp63);
			float fTemp65 = cosf(fTemp63);
			fRec43[0] = ((fRec44[1] * fTemp64) + (fRec43[1] * fTemp65));
			fRec44[0] = (((fRec44[1] * fTemp65) + (fRec43[1] * (0 - fTemp64))) + iTemp4);
			float fTemp66 = (fConst3 * (fTemp62 * ((439.956f * (fRec43[0] * fTemp7)) + 4.4e+02f)));
			float fTemp67 = sinf(fTemp66);
			float fTemp68 = cosf(fTemp66);
			fRec40[0] = ((fRec41[1] * fTemp67) + (fRec40[1] * fTemp68));
			fRec41[0] = (((fRec40[1] * (0 - fTemp67)) + (fRec41[1] * fTemp68)) + iTemp4);
			float fTemp69 = powf(2.0f,(0.083333336f * (fRec42[0] + -68.9f)));
			float fTemp70 = (fConst9 * fTemp69);
			float fTemp71 = sinf(fTemp70);
			float fTemp72 = cosf(fTemp70);
			fRec47[0] = ((fRec48[1] * fTemp71) + (fRec47[1] * fTemp72));
			fRec48[0] = (((fRec48[1] * fTemp72) + (fRec47[1] * (0 - fTemp71))) + iTemp4);
			float fTemp73 = (fConst3 * (fTemp69 * ((440.044f * (fRec47[0] * fTemp12)) + 4.4e+02f)));
			float fTemp74 = sinf(fTemp73);
			float fTemp75 = cosf(fTemp73);
			fRec45[0] = ((fRec46[1] * fTemp74) + (fRec45[1] * fTemp75));
			fRec46[0] = (((fRec45[1] * (0 - fTemp74)) + (fRec46[1] * fTemp75)) + iTemp4);
			float fTemp76 = powf(2.0f,(0.083333336f * (fRec20[0] + -69.001f)));
			float fTemp77 = (fConst4 * fTemp76);
			float fTemp78 = sinf(fTemp77);
			float fTemp79 = cosf(fTemp77);
			fRec51[0] = ((fRec52[1] * fTemp78) + (fRec51[1] * fTemp79));
			fRec52[0] = (((fRec52[1] * fTemp79) + (fRec51[1] * (0 - fTemp78))) + iTemp4);
			float fTemp80 = (fConst3 * (fTemp76 * ((439.956f * (fRec51[0] * fTemp7)) + 4.4e+02f)));
			float fTemp81 = sinf(fTemp80);
			float fTemp82 = cosf(fTemp80);
			fRec49[0] = ((fRec50[1] * fTemp81) + (fRec49[1] * fTemp82));
			fRec50[0] = (((fRec49[1] * (0 - fTemp81)) + (fRec50[1] * fTemp82)) + iTemp4);
			float fTemp83 = powf(2.0f,(0.083333336f * (fRec42[0] + -69.0f)));
			float fTemp84 = (fConst10 * fTemp83);
			float fTemp85 = sinf(fTemp84);
			float fTemp86 = cosf(fTemp84);
			fRec55[0] = ((fRec56[1] * fTemp85) + (fRec55[1] * fTemp86));
			fRec56[0] = (((fRec56[1] * fTemp86) + (fRec55[1] * (0 - fTemp85))) + iTemp4);
			float fTemp87 = (fConst10 * (fTemp83 * ((fRec55[0] * fTemp20) + 1.0f)));
			float fTemp88 = sinf(fTemp87);
			float fTemp89 = cosf(fTemp87);
			fRec53[0] = ((fRec54[1] * fTemp88) + (fRec53[1] * fTemp89));
			fRec54[0] = (((fRec53[1] * (0 - fTemp88)) + (fRec54[1] * fTemp89)) + iTemp4);
			fRec57[0] = (fSlow8 + (fConst11 * fRec57[1]));
			fRec61[0] = (fSlow9 + (fConst13 * fRec61[1]));
			fRec62[0] = ((fConst16 * fRec63[1]) + (fConst17 * fRec62[1]));
			fRec63[0] = (((fConst17 * fRec63[1]) + (fConst18 * fRec62[1])) + iTemp4);
			fRec64[0] = (fSlow10 + (0.999f * fRec64[1]));
			float fTemp90 = (fConst10 * powf(2.0f,(0.083333336f * ((fRec61[0] + (0.1f * (fRec62[0] * fRec64[0]))) + -69.0f))));
			float fTemp91 = sinf(fTemp90);
			float fTemp92 = cosf(fTemp90);
			fRec59[0] = ((fRec60[1] * fTemp91) + (fRec59[1] * fTemp92));
			fRec60[0] = (((fRec60[1] * fTemp92) + (fRec59[1] * (0 - fTemp91))) + iTemp4);
			float fTemp93 = tanf((fConst19 * ((2800 * (1 - fRec7[0])) + 200)));
			float fTemp94 = (1.0f / fTemp93);
			float fTemp95 = (((fTemp94 + 1.4142135f) / fTemp93) + 1);
			fRec58[0] = (fRec59[0] - (((fRec58[2] * (((fTemp94 + -1.4142135f) / fTemp93) + 1)) + (2 * (fRec58[1] * (1 - (1.0f / faustpower<2>(fTemp93)))))) / fTemp95));
			float fTemp96 = ((0.05334838f * (fRec0[0] * (fRec1[0] + (fRec10[0] + (fRec14[0] + (fRec18[0] + (fRec23[0] + (fRec27[0] + (fRec32[0] + (fRec36[0] + (fRec40[0] + (fRec45[0] + (fRec49[0] + fRec53[0]))))))))))))) + (((fRec7[0] * fRec57[0]) * (fRec58[0] + (fRec58[2] + (2.0f * fRec58[1])))) / fTemp95));
			output0[i] = (FAUSTFLOAT)fTemp96;
			output1[i] = (FAUSTFLOAT)fTemp96;
			// post processing
			fRec58[2] = fRec58[1]; fRec58[1] = fRec58[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec57[1] = fRec57[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec0[1] = fRec0[0];
			iVec0[1] = iVec0[0];
		}
	}
};


#endif
