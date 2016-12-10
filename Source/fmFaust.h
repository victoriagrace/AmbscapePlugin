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
	float 	fConst3;
	float 	fConst4;
	float 	fConst5;
	float 	fConst6;
	float 	fConst7;
	float 	fConst8;
	float 	fConst9;
	float 	fConst10;
	int 	iVec0[2];
	float 	fConst11;
	float 	fConst12;
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	float 	fRec11[2];
	float 	fRec10[2];
	int 	IOTA;
	float 	fVec1[16384];
	float 	fConst17;
	int 	iConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fConst24;
	float 	fConst25;
	float 	fConst26;
	FAUSTFLOAT 	fcheckbox0;
	float 	fRec13[2];
	float 	fConst27;
	FAUSTFLOAT 	fslider0;
	float 	fRec16[2];
	float 	fConst28;
	float 	fConst29;
	float 	fConst30;
	float 	fRec17[2];
	float 	fConst31;
	float 	fRec18[2];
	FAUSTFLOAT 	fslider1;
	float 	fRec19[2];
	FAUSTFLOAT 	fslider2;
	float 	fRec20[2];
	float 	fConst32;
	float 	fRec21[2];
	float 	fRec22[2];
	float 	fRec14[2];
	float 	fRec15[2];
	float 	fConst33;
	float 	fRec25[2];
	float 	fRec26[2];
	float 	fRec23[2];
	float 	fRec24[2];
	float 	fConst34;
	float 	fRec29[2];
	float 	fRec30[2];
	float 	fRec27[2];
	float 	fRec28[2];
	float 	fRec33[2];
	float 	fRec34[2];
	float 	fRec31[2];
	float 	fRec32[2];
	float 	fRec37[2];
	float 	fRec38[2];
	float 	fRec35[2];
	float 	fRec36[2];
	float 	fRec41[2];
	float 	fRec42[2];
	float 	fRec39[2];
	float 	fRec40[2];
	FAUSTFLOAT 	fslider3;
	float 	fRec45[2];
	float 	fRec46[2];
	float 	fRec47[2];
	float 	fRec43[2];
	float 	fRec44[2];
	float 	fRec50[2];
	float 	fRec51[2];
	float 	fRec48[2];
	float 	fRec49[2];
	float 	fRec54[2];
	float 	fRec55[2];
	float 	fRec52[2];
	float 	fRec53[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec58[2];
	float 	fRec59[2];
	float 	fRec60[2];
	float 	fRec56[2];
	float 	fRec57[2];
	float 	fRec63[2];
	float 	fRec64[2];
	float 	fRec61[2];
	float 	fRec62[2];
	FAUSTFLOAT 	fslider5;
	float 	fRec67[2];
	float 	fRec68[2];
	float 	fRec69[2];
	float 	fRec65[2];
	float 	fRec66[2];
	float 	fRec72[2];
	float 	fRec73[2];
	float 	fRec70[2];
	float 	fRec71[2];
	float 	fRec76[2];
	float 	fRec77[2];
	float 	fRec74[2];
	float 	fRec75[2];
	float 	fRec80[2];
	float 	fRec81[2];
	float 	fRec78[2];
	float 	fRec79[2];
	float 	fConst35;
	float 	fConst36;
	float 	fConst37;
	float 	fConst38;
	float 	fConst39;
	float 	fConst40;
	float 	fRec82[2];
	float 	fConst41;
	float 	fConst42;
	float 	fConst43;
	float 	fConst44;
	float 	fConst45;
	float 	fConst46;
	float 	fConst47;
	float 	fConst48;
	float 	fRec87[2];
	float 	fConst49;
	float 	fRec88[2];
	float 	fConst50;
	float 	fConst51;
	float 	fConst52;
	FAUSTFLOAT 	fslider6;
	float 	fRec91[2];
	float 	fConst53;
	float 	fConst54;
	float 	fConst55;
	float 	fRec92[2];
	float 	fConst56;
	float 	fRec93[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec94[2];
	float 	fConst57;
	float 	fConst58;
	float 	fConst59;
	float 	fRec95[2];
	float 	fConst60;
	float 	fRec96[2];
	float 	fRec89[2];
	float 	fRec90[2];
	float 	fRec85[2];
	float 	fRec86[2];
	float 	fConst61;
	int 	iRec99[2];
	float 	fRec98[3];
	float 	fRec97[3];
	float 	fRec100[2];
	float 	fRec101[2];
	float 	fRec102[2];
	float 	fRec103[2];
	float 	fRec105[3];
	float 	fRec104[3];
	float 	fConst62;
	float 	fConst63;
	float 	fRec84[3];
	float 	fConst64;
	float 	fConst65;
	float 	fConst66;
	float 	fRec83[3];
	float 	fConst67;
	float 	fConst68;
	float 	fConst69;
	float 	fRec12[3];
	float 	fVec2[2048];
	int 	iConst70;
	float 	fVec3[2048];
	int 	iConst71;
	float 	fRec8[2];
	float 	fConst72;
	float 	fConst73;
	float 	fConst74;
	float 	fConst75;
	float 	fConst76;
	float 	fConst77;
	float 	fConst78;
	float 	fConst79;
	float 	fConst80;
	float 	fConst81;
	float 	fConst82;
	float 	fRec109[2];
	float 	fRec108[2];
	float 	fVec4[16384];
	float 	fConst83;
	int 	iConst84;
	float 	fVec5[4096];
	int 	iConst85;
	float 	fRec106[2];
	float 	fConst86;
	float 	fConst87;
	float 	fConst88;
	float 	fConst89;
	float 	fConst90;
	float 	fConst91;
	float 	fConst92;
	float 	fConst93;
	float 	fConst94;
	float 	fConst95;
	float 	fConst96;
	float 	fRec113[2];
	float 	fRec112[2];
	float 	fVec6[16384];
	float 	fConst97;
	int 	iConst98;
	float 	fVec7[4096];
	int 	iConst99;
	float 	fRec110[2];
	float 	fConst100;
	float 	fConst101;
	float 	fConst102;
	float 	fConst103;
	float 	fConst104;
	float 	fConst105;
	float 	fConst106;
	float 	fConst107;
	float 	fConst108;
	float 	fConst109;
	float 	fConst110;
	float 	fRec117[2];
	float 	fRec116[2];
	float 	fVec8[16384];
	float 	fConst111;
	int 	iConst112;
	float 	fVec9[2048];
	int 	iConst113;
	float 	fRec114[2];
	float 	fConst114;
	float 	fConst115;
	float 	fConst116;
	float 	fConst117;
	float 	fConst118;
	float 	fConst119;
	float 	fConst120;
	float 	fConst121;
	float 	fConst122;
	float 	fConst123;
	float 	fConst124;
	float 	fRec121[2];
	float 	fRec120[2];
	float 	fVec10[32768];
	float 	fConst125;
	int 	iConst126;
	float 	fVec11[4096];
	int 	iConst127;
	float 	fRec118[2];
	float 	fConst128;
	float 	fConst129;
	float 	fConst130;
	float 	fConst131;
	float 	fConst132;
	float 	fConst133;
	float 	fConst134;
	float 	fConst135;
	float 	fConst136;
	float 	fConst137;
	float 	fConst138;
	float 	fRec125[2];
	float 	fRec124[2];
	float 	fVec12[16384];
	float 	fConst139;
	int 	iConst140;
	float 	fVec13[4096];
	int 	iConst141;
	float 	fRec122[2];
	float 	fConst142;
	float 	fConst143;
	float 	fConst144;
	float 	fConst145;
	float 	fConst146;
	float 	fConst147;
	float 	fConst148;
	float 	fConst149;
	float 	fConst150;
	float 	fConst151;
	float 	fConst152;
	float 	fRec129[2];
	float 	fRec128[2];
	float 	fVec14[32768];
	float 	fConst153;
	int 	iConst154;
	float 	fVec15[4096];
	int 	iConst155;
	float 	fRec126[2];
	float 	fConst156;
	float 	fConst157;
	float 	fConst158;
	float 	fConst159;
	float 	fConst160;
	float 	fConst161;
	float 	fConst162;
	float 	fConst163;
	float 	fConst164;
	float 	fConst165;
	float 	fConst166;
	float 	fRec133[2];
	float 	fRec132[2];
	float 	fVec16[32768];
	float 	fConst167;
	int 	iConst168;
	float 	fVec17[2048];
	int 	iConst169;
	float 	fRec130[2];
	float 	fRec0[3];
	float 	fRec1[3];
	float 	fRec2[3];
	float 	fRec3[3];
	float 	fRec4[3];
	float 	fRec5[3];
	float 	fRec6[3];
	float 	fRec7[3];
	float 	fConst170;
	float 	fConst171;
	float 	fRec134[2];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("oscillator.lib/name", "Faust Oscillator Library");
		m->declare("oscillator.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("oscillator.lib/copyright", "Julius O. Smith III");
		m->declare("oscillator.lib/version", "1.11");
		m->declare("oscillator.lib/license", "STK-4.3");
		m->declare("oscillator.lib/deprecated", "This library is deprecated and is not maintained anymore. It might be removed in future released.");
		m->declare("miscoscillator.lib/name", "Faust Oscillator Library");
		m->declare("miscoscillator.lib/version", "0.0");
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("noise.lib/name", "Faust Noise Generator Library");
		m->declare("noise.lib/version", "0.0");
		m->declare("reverb.lib/name", "Faust Reverb Library");
		m->declare("reverb.lib/version", "0.0");
		m->declare("delay.lib/name", "Faust Delay Library");
		m->declare("delay.lib/version", "0.0");
		m->declare("route.lib/name", "Faust Signal Routing Library");
		m->declare("route.lib/version", "0.0");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = min(1.92e+05f, max(1.0f, (float)fSamplingFreq));
		fConst1 = cosf((50265.484f / float(fConst0)));
		fConst2 = floorf(((0.153129f * fConst0) + 0.5f));
		fConst3 = ((0 - (6.9077554f * fConst2)) / fConst0);
		fConst4 = expf((0.125f * fConst3));
		fConst5 = faustpower<2>(fConst4);
		fConst6 = (1.0f - (fConst1 * fConst5));
		fConst7 = (1.0f - fConst5);
		fConst8 = (fConst6 / fConst7);
		fConst9 = sqrtf(max((float)0, ((faustpower<2>(fConst6) / faustpower<2>(fConst7)) + -1.0f)));
		fConst10 = (fConst8 - fConst9);
		fConst11 = (fConst4 * (fConst9 + (1.0f - fConst8)));
		fConst12 = ((expf((0.16666667f * fConst3)) / fConst4) + -1);
		fConst13 = (1.0f / tanf((942.4778f / fConst0)));
		fConst14 = (fConst13 + 1);
		fConst15 = (1.0f / fConst14);
		fConst16 = (0 - ((1 - fConst13) / fConst14));
		fConst17 = floorf(((0.020346f * fConst0) + 0.5f));
		iConst18 = int((int((fConst2 - fConst17)) & 16383));
		fConst19 = tanf((188.49556f / fConst0));
		fConst20 = (1.0f / fConst19);
		fConst21 = (((fConst20 + 1.4142135f) / fConst19) + 1);
		fConst22 = (0.3f / fConst21);
		fConst23 = (1.0f / faustpower<2>(fConst19));
		fConst24 = (2 * (0 - fConst23));
		fConst25 = expf((0 - (0.625f / fConst0)));
		fConst26 = (1.0f - fConst25);
		fConst27 = (6.2831855f / fConst0);
		fConst28 = (0.41887903f / fConst0);
		fConst29 = sinf(fConst28);
		fConst30 = cosf(fConst28);
		fConst31 = (0 - fConst29);
		fConst32 = (2764.3252f / fConst0);
		fConst33 = (2764.878f / fConst0);
		fConst34 = (2764.6016f / fConst0);
		fConst35 = tanf((12566.371f / fConst0));
		fConst36 = (1.0f / fConst35);
		fConst37 = (((fConst36 + 1.4142135f) / fConst35) + 1);
		fConst38 = (0.49763396f / fConst37);
		fConst39 = expf((0 - (1.8181819f / fConst0)));
		fConst40 = (1.0f - fConst39);
		fConst41 = tanf((3141.5928f / fConst0));
		fConst42 = (1.0f / fConst41);
		fConst43 = (1.0f / (((fConst42 + 1.4142135f) / fConst41) + 1));
		fConst44 = (1.0f / faustpower<2>(fConst41));
		fConst45 = (2 * (0 - fConst44));
		fConst46 = (0.3926991f / fConst0);
		fConst47 = sinf(fConst46);
		fConst48 = cosf(fConst46);
		fConst49 = (0 - fConst47);
		fConst50 = (5529.203f / fConst0);
		fConst51 = expf((0 - (12.5f / fConst0)));
		fConst52 = (1.0f - fConst51);
		fConst53 = (18.912388f / fConst0);
		fConst54 = sinf(fConst53);
		fConst55 = cosf(fConst53);
		fConst56 = (0 - fConst54);
		fConst57 = (37.699112f / fConst0);
		fConst58 = sinf(fConst57);
		fConst59 = cosf(fConst57);
		fConst60 = (0 - fConst58);
		fConst61 = (1382.3008f / fConst0);
		fConst62 = (((fConst42 + -1.4142135f) / fConst41) + 1);
		fConst63 = (2 * (1 - fConst44));
		fConst64 = (1.0f / fConst37);
		fConst65 = (((fConst36 + -1.4142135f) / fConst35) + 1);
		fConst66 = (2 * (1 - (1.0f / faustpower<2>(fConst35))));
		fConst67 = (1.0f / fConst21);
		fConst68 = (((fConst20 + -1.4142135f) / fConst19) + 1);
		fConst69 = (2 * (1 - fConst23));
		iConst70 = int((int((0.01f * fConst0)) & 8191));
		iConst71 = int((int((fConst17 + -1)) & 2047));
		fConst72 = floorf(((0.174713f * fConst0) + 0.5f));
		fConst73 = ((0 - (6.9077554f * fConst72)) / fConst0);
		fConst74 = expf((0.125f * fConst73));
		fConst75 = faustpower<2>(fConst74);
		fConst76 = (1.0f - (fConst75 * fConst1));
		fConst77 = (1.0f - fConst75);
		fConst78 = (fConst76 / fConst77);
		fConst79 = sqrtf(max((float)0, ((faustpower<2>(fConst76) / faustpower<2>(fConst77)) + -1.0f)));
		fConst80 = (fConst78 - fConst79);
		fConst81 = ((fConst79 + (1.0f - fConst78)) * fConst74);
		fConst82 = ((expf((0.16666667f * fConst73)) / fConst74) + -1);
		fConst83 = floorf(((0.022904f * fConst0) + 0.5f));
		iConst84 = int((int((fConst72 - fConst83)) & 16383));
		iConst85 = int((int((fConst83 + -1)) & 4095));
		fConst86 = floorf(((0.127837f * fConst0) + 0.5f));
		fConst87 = ((0 - (6.9077554f * fConst86)) / fConst0);
		fConst88 = expf((0.125f * fConst87));
		fConst89 = faustpower<2>(fConst88);
		fConst90 = (1.0f - (fConst1 * fConst89));
		fConst91 = (1.0f - fConst89);
		fConst92 = (fConst90 / fConst91);
		fConst93 = sqrtf(max((float)0, ((faustpower<2>(fConst90) / faustpower<2>(fConst91)) + -1.0f)));
		fConst94 = (fConst92 - fConst93);
		fConst95 = ((fConst93 + (1.0f - fConst92)) * fConst88);
		fConst96 = ((expf((0.16666667f * fConst87)) / fConst88) + -1);
		fConst97 = floorf(((0.031604f * fConst0) + 0.5f));
		iConst98 = int((int((fConst86 - fConst97)) & 16383));
		iConst99 = int((int((fConst97 + -1)) & 4095));
		fConst100 = floorf(((0.125f * fConst0) + 0.5f));
		fConst101 = ((0 - (6.9077554f * fConst100)) / fConst0);
		fConst102 = expf((0.125f * fConst101));
		fConst103 = faustpower<2>(fConst102);
		fConst104 = (1.0f - (fConst103 * fConst1));
		fConst105 = (1.0f - fConst103);
		fConst106 = (fConst104 / fConst105);
		fConst107 = sqrtf(max((float)0, ((faustpower<2>(fConst104) / faustpower<2>(fConst105)) + -1.0f)));
		fConst108 = (fConst106 - fConst107);
		fConst109 = (fConst102 * (fConst107 + (1.0f - fConst106)));
		fConst110 = ((expf((0.16666667f * fConst101)) / fConst102) + -1);
		fConst111 = floorf(((0.013458f * fConst0) + 0.5f));
		iConst112 = int((int((fConst100 - fConst111)) & 16383));
		iConst113 = int((int((fConst111 + -1)) & 2047));
		fConst114 = floorf(((0.210389f * fConst0) + 0.5f));
		fConst115 = ((0 - (6.9077554f * fConst114)) / fConst0);
		fConst116 = expf((0.125f * fConst115));
		fConst117 = faustpower<2>(fConst116);
		fConst118 = (1.0f - (fConst1 * fConst117));
		fConst119 = (1.0f - fConst117);
		fConst120 = (fConst118 / fConst119);
		fConst121 = sqrtf(max((float)0, ((faustpower<2>(fConst118) / faustpower<2>(fConst119)) + -1.0f)));
		fConst122 = (fConst120 - fConst121);
		fConst123 = ((fConst121 + (1.0f - fConst120)) * fConst116);
		fConst124 = ((expf((0.16666667f * fConst115)) / fConst116) + -1);
		fConst125 = floorf(((0.024421f * fConst0) + 0.5f));
		iConst126 = int((int((fConst114 - fConst125)) & 32767));
		iConst127 = int((int((fConst125 + -1)) & 4095));
		fConst128 = floorf(((0.192303f * fConst0) + 0.5f));
		fConst129 = ((0 - (6.9077554f * fConst128)) / fConst0);
		fConst130 = expf((0.125f * fConst129));
		fConst131 = faustpower<2>(fConst130);
		fConst132 = (1.0f - (fConst131 * fConst1));
		fConst133 = (1.0f - fConst131);
		fConst134 = (fConst132 / fConst133);
		fConst135 = sqrtf(max((float)0, ((faustpower<2>(fConst132) / faustpower<2>(fConst133)) + -1.0f)));
		fConst136 = (fConst134 - fConst135);
		fConst137 = (fConst130 * (fConst135 + (1.0f - fConst134)));
		fConst138 = ((expf((0.16666667f * fConst129)) / fConst130) + -1);
		fConst139 = floorf(((0.029291f * fConst0) + 0.5f));
		iConst140 = int((int((fConst128 - fConst139)) & 16383));
		iConst141 = int((int((fConst139 + -1)) & 4095));
		fConst142 = floorf(((0.256891f * fConst0) + 0.5f));
		fConst143 = ((0 - (6.9077554f * fConst142)) / fConst0);
		fConst144 = expf((0.125f * fConst143));
		fConst145 = faustpower<2>(fConst144);
		fConst146 = (1.0f - (fConst1 * fConst145));
		fConst147 = (1.0f - fConst145);
		fConst148 = (fConst146 / fConst147);
		fConst149 = sqrtf(max((float)0, ((faustpower<2>(fConst146) / faustpower<2>(fConst147)) + -1.0f)));
		fConst150 = (fConst148 - fConst149);
		fConst151 = ((fConst149 + (1.0f - fConst148)) * fConst144);
		fConst152 = ((expf((0.16666667f * fConst143)) / fConst144) + -1);
		fConst153 = floorf(((0.027333f * fConst0) + 0.5f));
		iConst154 = int((int((fConst142 - fConst153)) & 32767));
		iConst155 = int((int((fConst153 + -1)) & 4095));
		fConst156 = floorf(((0.219991f * fConst0) + 0.5f));
		fConst157 = ((0 - (6.9077554f * fConst156)) / fConst0);
		fConst158 = expf((0.125f * fConst157));
		fConst159 = faustpower<2>(fConst158);
		fConst160 = (1.0f - (fConst159 * fConst1));
		fConst161 = (1.0f - fConst159);
		fConst162 = (fConst160 / fConst161);
		fConst163 = sqrtf(max((float)0, ((faustpower<2>(fConst160) / faustpower<2>(fConst161)) + -1.0f)));
		fConst164 = (fConst162 - fConst163);
		fConst165 = ((fConst163 + (1.0f - fConst162)) * fConst158);
		fConst166 = ((expf((0.16666667f * fConst157)) / fConst158) + -1);
		fConst167 = floorf(((0.019123f * fConst0) + 0.5f));
		iConst168 = int((int((fConst156 - fConst167)) & 32767));
		iConst169 = int((int((fConst167 + -1)) & 2047));
		fConst170 = expf((0 - (1.0f / fConst0)));
		fConst171 = (1.0f - fConst170);
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
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		IOTA = 0;
		for (int i=0; i<16384; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) iRec99[i] = 0;
		for (int i=0; i<3; i++) fRec98[i] = 0;
		for (int i=0; i<3; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<3; i++) fRec105[i] = 0;
		for (int i=0; i<3; i++) fRec104[i] = 0;
		for (int i=0; i<3; i++) fRec84[i] = 0;
		for (int i=0; i<3; i++) fRec83[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<2048; i++) fVec2[i] = 0;
		for (int i=0; i<2048; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<16384; i++) fVec4[i] = 0;
		for (int i=0; i<4096; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<16384; i++) fVec6[i] = 0;
		for (int i=0; i<4096; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		for (int i=0; i<2; i++) fRec116[i] = 0;
		for (int i=0; i<16384; i++) fVec8[i] = 0;
		for (int i=0; i<2048; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) fRec114[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<32768; i++) fVec10[i] = 0;
		for (int i=0; i<4096; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec118[i] = 0;
		for (int i=0; i<2; i++) fRec125[i] = 0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
		for (int i=0; i<16384; i++) fVec12[i] = 0;
		for (int i=0; i<4096; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec122[i] = 0;
		for (int i=0; i<2; i++) fRec129[i] = 0;
		for (int i=0; i<2; i++) fRec128[i] = 0;
		for (int i=0; i<32768; i++) fVec14[i] = 0;
		for (int i=0; i<4096; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec126[i] = 0;
		for (int i=0; i<2; i++) fRec133[i] = 0;
		for (int i=0; i<2; i++) fRec132[i] = 0;
		for (int i=0; i<32768; i++) fVec16[i] = 0;
		for (int i=0; i<2048; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec130[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec134[i] = 0;
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
		ui_interface->addHorizontalSlider("alto", &fslider4, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("bass", &fslider0, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addCheckButton("gate", &fcheckbox0);
		ui_interface->addHorizontalSlider("indx", &fslider1, 1.0f, 0.0f, 2e+01f, 0.01f);
		ui_interface->addHorizontalSlider("lead", &fslider6, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("pull", &fslider2, 0.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->addHorizontalSlider("rotation", &fslider7, 0.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->addHorizontalSlider("soprano", &fslider5, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("tenor", &fslider3, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = float(fcheckbox0);
		float 	fSlow1 = (fConst26 * fSlow0);
		float 	fSlow2 = (0.001f * float(fslider0));
		float 	fSlow3 = (0.001f * float(fslider1));
		float 	fSlow4 = float(fslider2);
		float 	fSlow5 = (0.001f * fSlow4);
		float 	fSlow6 = (0.001f * float(fslider3));
		float 	fSlow7 = (0.001f * float(fslider4));
		float 	fSlow8 = (0.001f * float(fslider5));
		float 	fSlow9 = (fConst40 * fSlow0);
		float 	fSlow10 = (fConst52 * float(fslider6));
		float 	fSlow11 = (0.001f * float(fslider7));
		float 	fSlow12 = (fConst171 * fSlow4);
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			fRec11[0] = ((fConst15 * (fRec0[1] + fRec0[2])) + (fConst16 * fRec11[1]));
			fRec10[0] = ((fConst10 * fRec10[1]) + (fConst11 * (fRec0[1] + (fConst12 * fRec11[0]))));
			fVec1[IOTA&16383] = ((0.35355338f * fRec10[0]) + 1e-20f);
			fRec13[0] = (fSlow1 + (fConst25 * fRec13[1]));
			fRec16[0] = (fSlow2 + (0.999f * fRec16[1]));
			float fTemp0 = powf(2.0f,(0.083333336f * (fRec16[0] + -81.001f)));
			fRec17[0] = ((fConst29 * fRec18[1]) + (fConst30 * fRec17[1]));
			int iTemp1 = (1 - iVec0[1]);
			fRec18[0] = (((fConst30 * fRec18[1]) + (fConst31 * fRec17[1])) + iTemp1);
			float fTemp2 = (0.25f * (fRec17[0] + 1));
			fRec19[0] = (fSlow3 + (0.999f * fRec19[1]));
			fRec20[0] = (fSlow5 + (0.999f * fRec20[1]));
			float fTemp3 = (3 * fRec20[0]);
			float fTemp4 = (fRec19[0] + fTemp3);
			float fTemp5 = (fTemp2 + (1.01f * fTemp4));
			float fTemp6 = (fConst32 * fTemp0);
			float fTemp7 = sinf(fTemp6);
			float fTemp8 = cosf(fTemp6);
			fRec21[0] = ((fRec22[1] * fTemp7) + (fRec21[1] * fTemp8));
			fRec22[0] = (((fRec22[1] * fTemp8) + (fRec21[1] * (0 - fTemp7))) + iTemp1);
			float fTemp9 = (fConst27 * (fTemp0 * ((439.956f * (fTemp5 * fRec21[0])) + 4.4e+02f)));
			float fTemp10 = sinf(fTemp9);
			float fTemp11 = cosf(fTemp9);
			fRec14[0] = ((fRec15[1] * fTemp10) + (fRec14[1] * fTemp11));
			fRec15[0] = (((fRec15[1] * fTemp11) + (fRec14[1] * (0 - fTemp10))) + iTemp1);
			float fTemp12 = powf(2.0f,(0.083333336f * (fRec16[0] + -80.9f)));
			float fTemp13 = ((fTemp3 + (fRec17[0] + fRec19[0])) + 1);
			float fTemp14 = (fConst33 * fTemp12);
			float fTemp15 = sinf(fTemp14);
			float fTemp16 = cosf(fTemp14);
			fRec25[0] = ((fRec26[1] * fTemp15) + (fRec25[1] * fTemp16));
			fRec26[0] = (((fRec26[1] * fTemp16) + (fRec25[1] * (0 - fTemp15))) + iTemp1);
			float fTemp17 = (fConst27 * (fTemp12 * ((440.044f * (fTemp13 * fRec25[0])) + 4.4e+02f)));
			float fTemp18 = sinf(fTemp17);
			float fTemp19 = cosf(fTemp17);
			fRec23[0] = ((fRec24[1] * fTemp18) + (fRec23[1] * fTemp19));
			fRec24[0] = (((fRec24[1] * fTemp19) + (fRec23[1] * (0 - fTemp18))) + iTemp1);
			float fTemp20 = powf(2.0f,(0.083333336f * (fRec16[0] + -81.0f)));
			float fTemp21 = (fTemp2 + (0.99f * fTemp4));
			float fTemp22 = (fConst34 * fTemp20);
			float fTemp23 = sinf(fTemp22);
			float fTemp24 = cosf(fTemp22);
			fRec29[0] = ((fRec30[1] * fTemp23) + (fRec29[1] * fTemp24));
			fRec30[0] = (((fRec30[1] * fTemp24) + (fRec29[1] * (0 - fTemp23))) + iTemp1);
			float fTemp25 = (fConst34 * (fTemp20 * ((fTemp21 * fRec29[0]) + 1.0f)));
			float fTemp26 = sinf(fTemp25);
			float fTemp27 = cosf(fTemp25);
			fRec27[0] = ((fRec28[1] * fTemp26) + (fRec27[1] * fTemp27));
			fRec28[0] = (((fRec28[1] * fTemp27) + (fRec27[1] * (0 - fTemp26))) + iTemp1);
			float fTemp28 = powf(2.0f,(0.083333336f * (fRec16[0] + -69.001f)));
			float fTemp29 = (fConst32 * fTemp28);
			float fTemp30 = sinf(fTemp29);
			float fTemp31 = cosf(fTemp29);
			fRec33[0] = ((fRec34[1] * fTemp30) + (fRec33[1] * fTemp31));
			fRec34[0] = (((fRec34[1] * fTemp31) + (fRec33[1] * (0 - fTemp30))) + iTemp1);
			float fTemp32 = (fConst27 * (fTemp28 * ((439.956f * (fRec33[0] * (fTemp2 + (4.04f * fTemp4)))) + 4.4e+02f)));
			float fTemp33 = sinf(fTemp32);
			float fTemp34 = cosf(fTemp32);
			fRec31[0] = ((fRec32[1] * fTemp33) + (fRec31[1] * fTemp34));
			fRec32[0] = (((fRec32[1] * fTemp34) + (fRec31[1] * (0 - fTemp33))) + iTemp1);
			float fTemp35 = powf(2.0f,(0.083333336f * (fRec16[0] + -68.9f)));
			float fTemp36 = (fConst33 * fTemp35);
			float fTemp37 = sinf(fTemp36);
			float fTemp38 = cosf(fTemp36);
			fRec37[0] = ((fRec38[1] * fTemp37) + (fRec37[1] * fTemp38));
			fRec38[0] = (((fRec38[1] * fTemp38) + (fRec37[1] * (0 - fTemp37))) + iTemp1);
			float fTemp39 = (fConst27 * (fTemp35 * ((440.044f * (fRec37[0] * ((fRec17[0] + (4 * fTemp4)) + 1))) + 4.4e+02f)));
			float fTemp40 = sinf(fTemp39);
			float fTemp41 = cosf(fTemp39);
			fRec35[0] = ((fRec36[1] * fTemp40) + (fRec35[1] * fTemp41));
			fRec36[0] = (((fRec36[1] * fTemp41) + (fRec35[1] * (0 - fTemp40))) + iTemp1);
			float fTemp42 = powf(2.0f,(0.083333336f * (fRec16[0] + -69.0f)));
			float fTemp43 = (fConst34 * fTemp42);
			float fTemp44 = sinf(fTemp43);
			float fTemp45 = cosf(fTemp43);
			fRec41[0] = ((fRec42[1] * fTemp44) + (fRec41[1] * fTemp45));
			fRec42[0] = (((fRec42[1] * fTemp45) + (fRec41[1] * (0 - fTemp44))) + iTemp1);
			float fTemp46 = (fConst34 * (fTemp42 * ((fRec41[0] * (fTemp2 + (3.96f * fTemp4))) + 1.0f)));
			float fTemp47 = sinf(fTemp46);
			float fTemp48 = cosf(fTemp46);
			fRec39[0] = ((fRec40[1] * fTemp47) + (fRec39[1] * fTemp48));
			fRec40[0] = (((fRec40[1] * fTemp48) + (fRec39[1] * (0 - fTemp47))) + iTemp1);
			fRec45[0] = (fSlow6 + (0.999f * fRec45[1]));
			float fTemp49 = powf(2.0f,(0.083333336f * (fRec45[0] + -69.001f)));
			float fTemp50 = (fConst32 * fTemp49);
			float fTemp51 = sinf(fTemp50);
			float fTemp52 = cosf(fTemp50);
			fRec46[0] = ((fRec47[1] * fTemp51) + (fRec46[1] * fTemp52));
			fRec47[0] = (((fRec47[1] * fTemp52) + (fRec46[1] * (0 - fTemp51))) + iTemp1);
			float fTemp53 = (fConst27 * (fTemp49 * ((439.956f * (fTemp5 * fRec46[0])) + 4.4e+02f)));
			float fTemp54 = sinf(fTemp53);
			float fTemp55 = cosf(fTemp53);
			fRec43[0] = ((fRec44[1] * fTemp54) + (fRec43[1] * fTemp55));
			fRec44[0] = (((fRec44[1] * fTemp55) + (fRec43[1] * (0 - fTemp54))) + iTemp1);
			float fTemp56 = powf(2.0f,(0.083333336f * (fRec45[0] + -68.9f)));
			float fTemp57 = (fConst33 * fTemp56);
			float fTemp58 = sinf(fTemp57);
			float fTemp59 = cosf(fTemp57);
			fRec50[0] = ((fRec51[1] * fTemp58) + (fRec50[1] * fTemp59));
			fRec51[0] = (((fRec51[1] * fTemp59) + (fRec50[1] * (0 - fTemp58))) + iTemp1);
			float fTemp60 = (fConst27 * (fTemp56 * ((440.044f * (fTemp13 * fRec50[0])) + 4.4e+02f)));
			float fTemp61 = sinf(fTemp60);
			float fTemp62 = cosf(fTemp60);
			fRec48[0] = ((fRec49[1] * fTemp61) + (fRec48[1] * fTemp62));
			fRec49[0] = (((fRec49[1] * fTemp62) + (fRec48[1] * (0 - fTemp61))) + iTemp1);
			float fTemp63 = powf(2.0f,(0.083333336f * (fRec45[0] + -69.0f)));
			float fTemp64 = (fConst34 * fTemp63);
			float fTemp65 = sinf(fTemp64);
			float fTemp66 = cosf(fTemp64);
			fRec54[0] = ((fRec55[1] * fTemp65) + (fRec54[1] * fTemp66));
			fRec55[0] = (((fRec55[1] * fTemp66) + (fRec54[1] * (0 - fTemp65))) + iTemp1);
			float fTemp67 = (fConst34 * (fTemp63 * ((fTemp21 * fRec54[0]) + 1.0f)));
			float fTemp68 = sinf(fTemp67);
			float fTemp69 = cosf(fTemp67);
			fRec52[0] = ((fRec53[1] * fTemp68) + (fRec52[1] * fTemp69));
			fRec53[0] = (((fRec53[1] * fTemp69) + (fRec52[1] * (0 - fTemp68))) + iTemp1);
			fRec58[0] = (fSlow7 + (0.999f * fRec58[1]));
			float fTemp70 = powf(2.0f,(0.083333336f * (fRec58[0] + -69.001f)));
			float fTemp71 = (fConst32 * fTemp70);
			float fTemp72 = sinf(fTemp71);
			float fTemp73 = cosf(fTemp71);
			fRec59[0] = ((fRec60[1] * fTemp72) + (fRec59[1] * fTemp73));
			fRec60[0] = (((fRec60[1] * fTemp73) + (fRec59[1] * (0 - fTemp72))) + iTemp1);
			float fTemp74 = (fConst27 * (fTemp70 * ((439.956f * (fTemp5 * fRec59[0])) + 4.4e+02f)));
			float fTemp75 = sinf(fTemp74);
			float fTemp76 = cosf(fTemp74);
			fRec56[0] = ((fRec57[1] * fTemp75) + (fRec56[1] * fTemp76));
			fRec57[0] = (((fRec57[1] * fTemp76) + (fRec56[1] * (0 - fTemp75))) + iTemp1);
			float fTemp77 = powf(2.0f,(0.083333336f * (fRec58[0] + -68.9f)));
			float fTemp78 = (fConst33 * fTemp77);
			float fTemp79 = sinf(fTemp78);
			float fTemp80 = cosf(fTemp78);
			fRec63[0] = ((fRec64[1] * fTemp79) + (fRec63[1] * fTemp80));
			fRec64[0] = (((fRec64[1] * fTemp80) + (fRec63[1] * (0 - fTemp79))) + iTemp1);
			float fTemp81 = (fConst27 * (fTemp77 * ((440.044f * (fTemp13 * fRec63[0])) + 4.4e+02f)));
			float fTemp82 = sinf(fTemp81);
			float fTemp83 = cosf(fTemp81);
			fRec61[0] = ((fRec62[1] * fTemp82) + (fRec61[1] * fTemp83));
			fRec62[0] = (((fRec62[1] * fTemp83) + (fRec61[1] * (0 - fTemp82))) + iTemp1);
			fRec67[0] = (fSlow8 + (0.999f * fRec67[1]));
			float fTemp84 = powf(2.0f,(0.083333336f * (fRec67[0] + -69.0f)));
			float fTemp85 = (fConst34 * fTemp84);
			float fTemp86 = sinf(fTemp85);
			float fTemp87 = cosf(fTemp85);
			fRec68[0] = ((fRec69[1] * fTemp86) + (fRec68[1] * fTemp87));
			fRec69[0] = (((fRec69[1] * fTemp87) + (fRec68[1] * (0 - fTemp86))) + iTemp1);
			float fTemp88 = (fConst34 * (fTemp84 * ((fRec68[0] * fTemp21) + 1.0f)));
			float fTemp89 = sinf(fTemp88);
			float fTemp90 = cosf(fTemp88);
			fRec65[0] = ((fRec66[1] * fTemp89) + (fRec65[1] * fTemp90));
			fRec66[0] = (((fRec66[1] * fTemp90) + (fRec65[1] * (0 - fTemp89))) + iTemp1);
			float fTemp91 = powf(2.0f,(0.083333336f * (fRec67[0] + -68.9f)));
			float fTemp92 = (fConst33 * fTemp91);
			float fTemp93 = sinf(fTemp92);
			float fTemp94 = cosf(fTemp92);
			fRec72[0] = ((fRec73[1] * fTemp93) + (fRec72[1] * fTemp94));
			fRec73[0] = (((fRec73[1] * fTemp94) + (fRec72[1] * (0 - fTemp93))) + iTemp1);
			float fTemp95 = (fConst27 * (fTemp91 * ((440.044f * (fRec72[0] * fTemp13)) + 4.4e+02f)));
			float fTemp96 = sinf(fTemp95);
			float fTemp97 = cosf(fTemp95);
			fRec70[0] = ((fRec71[1] * fTemp96) + (fRec70[1] * fTemp97));
			fRec71[0] = (((fRec71[1] * fTemp97) + (fRec70[1] * (0 - fTemp96))) + iTemp1);
			float fTemp98 = powf(2.0f,(0.083333336f * (fRec67[0] + -69.001f)));
			float fTemp99 = (fConst32 * fTemp98);
			float fTemp100 = sinf(fTemp99);
			float fTemp101 = cosf(fTemp99);
			fRec76[0] = ((fRec77[1] * fTemp100) + (fRec76[1] * fTemp101));
			fRec77[0] = (((fRec77[1] * fTemp101) + (fRec76[1] * (0 - fTemp100))) + iTemp1);
			float fTemp102 = (fConst27 * (fTemp98 * ((439.956f * (fRec76[0] * fTemp5)) + 4.4e+02f)));
			float fTemp103 = sinf(fTemp102);
			float fTemp104 = cosf(fTemp102);
			fRec74[0] = ((fRec75[1] * fTemp103) + (fRec74[1] * fTemp104));
			fRec75[0] = (((fRec75[1] * fTemp104) + (fRec74[1] * (0 - fTemp103))) + iTemp1);
			float fTemp105 = powf(2.0f,(0.083333336f * (fRec58[0] + -69.0f)));
			float fTemp106 = (fConst34 * fTemp105);
			float fTemp107 = sinf(fTemp106);
			float fTemp108 = cosf(fTemp106);
			fRec80[0] = ((fRec81[1] * fTemp107) + (fRec80[1] * fTemp108));
			fRec81[0] = (((fRec81[1] * fTemp108) + (fRec80[1] * (0 - fTemp107))) + iTemp1);
			float fTemp109 = (fConst34 * (fTemp105 * ((fTemp21 * fRec80[0]) + 1.0f)));
			float fTemp110 = sinf(fTemp109);
			float fTemp111 = cosf(fTemp109);
			fRec78[0] = ((fRec79[1] * fTemp110) + (fRec78[1] * fTemp111));
			fRec79[0] = (((fRec79[1] * fTemp111) + (fRec78[1] * (0 - fTemp110))) + iTemp1);
			fRec82[0] = (fSlow9 + (fConst39 * fRec82[1]));
			fRec87[0] = ((fConst47 * fRec88[1]) + (fConst48 * fRec87[1]));
			fRec88[0] = (((fConst48 * fRec88[1]) + (fConst49 * fRec87[1])) + iTemp1);
			fRec91[0] = (fSlow10 + (fConst51 * fRec91[1]));
			fRec92[0] = ((fConst54 * fRec93[1]) + (fConst55 * fRec92[1]));
			fRec93[0] = (((fConst55 * fRec93[1]) + (fConst56 * fRec92[1])) + iTemp1);
			fRec94[0] = (fSlow11 + (0.999f * fRec94[1]));
			fRec95[0] = ((fConst58 * fRec96[1]) + (fConst59 * fRec95[1]));
			fRec96[0] = (((fConst59 * fRec96[1]) + (fConst60 * fRec95[1])) + iTemp1);
			float fTemp112 = powf(2.0f,(0.083333336f * ((fRec91[0] + (0.1f * ((fRec92[0] * fRec94[0]) + (fRec20[0] * fRec95[0])))) + -69.0f)));
			float fTemp113 = (fConst50 * fTemp112);
			float fTemp114 = sinf(fTemp113);
			float fTemp115 = cosf(fTemp113);
			fRec89[0] = ((fRec90[1] * fTemp114) + (fRec89[1] * fTemp115));
			fRec90[0] = (((fRec89[1] * (0 - fTemp114)) + (fRec90[1] * fTemp115)) + iTemp1);
			float fTemp116 = (fConst27 * (((8.8e+02f * (((0.9f * (fRec87[0] + 1)) + 0.1f) * fRec89[0])) + 1.76e+03f) * fTemp112));
			float fTemp117 = sinf(fTemp116);
			float fTemp118 = cosf(fTemp116);
			fRec85[0] = ((fRec86[1] * fTemp117) + (fRec85[1] * fTemp118));
			fRec86[0] = (((fRec85[1] * (0 - fTemp117)) + (fRec86[1] * fTemp118)) + iTemp1);
			float fTemp119 = powf(2.0f,(0.083333336f * (fRec91[0] + -57.0f)));
			float fTemp120 = tanf((fConst61 * fTemp119));
			float fTemp121 = (1.0f / fTemp120);
			float fTemp122 = (((fTemp121 + -0.025f) / fTemp120) + 1);
			float fTemp123 = (1 - (1.0f / faustpower<2>(fTemp120)));
			iRec99[0] = ((1103515245 * iRec99[1]) + 12345);
			float fTemp124 = (4.656613e-11f * iRec99[0]);
			float fTemp125 = (((fTemp121 + 0.025f) / fTemp120) + 1);
			fRec98[0] = (fTemp124 - (((2 * (fTemp123 * fRec98[1])) + (fTemp122 * fRec98[2])) / fTemp125));
			fRec97[0] = (0 - ((((fRec97[2] * fTemp122) + (2 * (fRec97[1] * fTemp123))) - ((fRec98[2] * (0 - (0.8f / fTemp120))) + (0.8f * (fRec98[0] / fTemp120)))) / fTemp125));
			float fTemp126 = powf(2.0f,(0.083333336f * (fRec91[0] + -69.0f)));
			float fTemp127 = (fConst34 * fTemp126);
			float fTemp128 = sinf(fTemp127);
			float fTemp129 = cosf(fTemp127);
			fRec100[0] = ((fRec101[1] * fTemp128) + (fRec100[1] * fTemp129));
			fRec101[0] = (((fRec101[1] * fTemp129) + (fRec100[1] * (0 - fTemp128))) + iTemp1);
			float fTemp130 = (fConst34 * fTemp119);
			float fTemp131 = sinf(fTemp130);
			float fTemp132 = cosf(fTemp130);
			fRec102[0] = ((fRec103[1] * fTemp131) + (fRec102[1] * fTemp132));
			fRec103[0] = (((fRec103[1] * fTemp132) + (fRec102[1] * (0 - fTemp131))) + iTemp1);
			float fTemp133 = tanf((fConst61 * fTemp126));
			float fTemp134 = (1.0f / fTemp133);
			float fTemp135 = (((fTemp134 + -0.025f) / fTemp133) + 1);
			float fTemp136 = (1 - (1.0f / faustpower<2>(fTemp133)));
			float fTemp137 = (((fTemp134 + 0.025f) / fTemp133) + 1);
			fRec105[0] = (fTemp124 - (((fTemp135 * fRec105[2]) + (2 * (fTemp136 * fRec105[1]))) / fTemp137));
			fRec104[0] = (0 - ((((fRec104[2] * fTemp135) + (2 * (fRec104[1] * fTemp136))) - ((fRec105[2] * (0 - (0.8f / fTemp133))) + (0.8f * (fRec105[0] / fTemp133)))) / fTemp137));
			fRec84[0] = (((0.5f * fRec85[0]) + ((((fRec97[2] * (0 - (0.9f / fTemp120))) + (0.9f * (fRec97[0] / fTemp120))) / fTemp125) + ((0.2f * (fRec100[0] + fRec102[0])) + (((fRec104[2] * (0 - (0.9f / fTemp133))) + (0.9f * (fRec104[0] / fTemp133))) / fTemp137)))) - (fConst43 * ((fConst62 * fRec84[2]) + (fConst63 * fRec84[1]))));
			fRec83[0] = ((fConst43 * ((fConst45 * fRec84[1]) + (fConst44 * (fRec84[2] + fRec84[0])))) - (fConst64 * ((fConst65 * fRec83[2]) + (fConst66 * fRec83[1]))));
			float fTemp138 = ((0.09486833f * (fRec13[0] * (fRec14[0] + (fRec23[0] + (fRec27[0] + (fRec31[0] + (fRec35[0] + (fRec39[0] + (fRec43[0] + (fRec48[0] + (fRec52[0] + (fRec56[0] + (fRec61[0] + (((fRec65[0] + fRec70[0]) + fRec74[0]) + fRec78[0])))))))))))))) + (fConst38 * ((faustpower<2>(fRec20[0]) * fRec82[0]) * (fRec83[0] + (fRec83[2] + (2.0f * fRec83[1]))))));
			fRec12[0] = (fTemp138 - (fConst67 * ((fConst68 * fRec12[2]) + (fConst69 * fRec12[1]))));
			fVec2[IOTA&2047] = ((fConst24 * fRec12[1]) + (fConst23 * (fRec12[2] + fRec12[0])));
			float fTemp139 = (fConst22 * fVec2[(IOTA-iConst70)&2047]);
			float fTemp140 = ((fVec1[(IOTA-iConst18)&16383] + fTemp139) - (0.6f * fRec8[1]));
			fVec3[IOTA&2047] = fTemp140;
			fRec8[0] = fVec3[(IOTA-iConst71)&2047];
			float 	fRec9 = (0.6f * fVec3[IOTA&2047]);
			fRec109[0] = ((fConst15 * (fRec4[1] + fRec4[2])) + (fConst16 * fRec109[1]));
			fRec108[0] = ((fConst80 * fRec108[1]) + (fConst81 * (fRec4[1] + (fConst82 * fRec109[0]))));
			fVec4[IOTA&16383] = ((0.35355338f * fRec108[0]) + 1e-20f);
			float fTemp141 = ((fVec4[(IOTA-iConst84)&16383] + fTemp139) - (0.6f * fRec106[1]));
			fVec5[IOTA&4095] = fTemp141;
			fRec106[0] = fVec5[(IOTA-iConst85)&4095];
			float 	fRec107 = (0.6f * fVec5[IOTA&4095]);
			fRec113[0] = ((fConst15 * (fRec2[1] + fRec2[2])) + (fConst16 * fRec113[1]));
			fRec112[0] = ((fConst94 * fRec112[1]) + (fConst95 * (fRec2[1] + (fConst96 * fRec113[0]))));
			fVec6[IOTA&16383] = ((0.35355338f * fRec112[0]) + 1e-20f);
			float fTemp142 = (fVec6[(IOTA-iConst98)&16383] - ((0.6f * fRec110[1]) + fTemp139));
			fVec7[IOTA&4095] = fTemp142;
			fRec110[0] = fVec7[(IOTA-iConst99)&4095];
			float 	fRec111 = (0.6f * fVec7[IOTA&4095]);
			fRec117[0] = ((fConst15 * (fRec6[1] + fRec6[2])) + (fConst16 * fRec117[1]));
			fRec116[0] = ((fConst108 * fRec116[1]) + (fConst109 * (fRec6[1] + (fConst110 * fRec117[0]))));
			fVec8[IOTA&16383] = ((0.35355338f * fRec116[0]) + 1e-20f);
			float fTemp143 = (fVec8[(IOTA-iConst112)&16383] - ((0.6f * fRec114[1]) + fTemp139));
			fVec9[IOTA&2047] = fTemp143;
			fRec114[0] = fVec9[(IOTA-iConst113)&2047];
			float 	fRec115 = (0.6f * fVec9[IOTA&2047]);
			fRec121[0] = ((fConst15 * (fRec1[1] + fRec1[2])) + (fConst16 * fRec121[1]));
			fRec120[0] = ((fConst122 * fRec120[1]) + (fConst123 * (fRec1[1] + (fConst124 * fRec121[0]))));
			fVec10[IOTA&32767] = ((0.35355338f * fRec120[0]) + 1e-20f);
			float fTemp144 = (fTemp139 + ((0.6f * fRec118[1]) + fVec10[(IOTA-iConst126)&32767]));
			fVec11[IOTA&4095] = fTemp144;
			fRec118[0] = fVec11[(IOTA-iConst127)&4095];
			float 	fRec119 = (0 - (0.6f * fVec11[IOTA&4095]));
			fRec125[0] = ((fConst15 * (fRec5[1] + fRec5[2])) + (fConst16 * fRec125[1]));
			fRec124[0] = ((fConst136 * fRec124[1]) + (fConst137 * (fRec5[1] + (fConst138 * fRec125[0]))));
			fVec12[IOTA&16383] = ((0.35355338f * fRec124[0]) + 1e-20f);
			float fTemp145 = (fTemp139 + ((0.6f * fRec122[1]) + fVec12[(IOTA-iConst140)&16383]));
			fVec13[IOTA&4095] = fTemp145;
			fRec122[0] = fVec13[(IOTA-iConst141)&4095];
			float 	fRec123 = (0 - (0.6f * fVec13[IOTA&4095]));
			fRec129[0] = ((fConst15 * (fRec3[1] + fRec3[2])) + (fConst16 * fRec129[1]));
			fRec128[0] = ((fConst150 * fRec128[1]) + (fConst151 * (fRec3[1] + (fConst152 * fRec129[0]))));
			fVec14[IOTA&32767] = ((0.35355338f * fRec128[0]) + 1e-20f);
			float fTemp146 = (((0.6f * fRec126[1]) + fVec14[(IOTA-iConst154)&32767]) - fTemp139);
			fVec15[IOTA&4095] = fTemp146;
			fRec126[0] = fVec15[(IOTA-iConst155)&4095];
			float 	fRec127 = (0 - (0.6f * fVec15[IOTA&4095]));
			fRec133[0] = ((fConst15 * (fRec7[1] + fRec7[2])) + (fConst16 * fRec133[1]));
			fRec132[0] = ((fConst164 * fRec132[1]) + (fConst165 * (fRec7[1] + (fConst166 * fRec133[0]))));
			fVec16[IOTA&32767] = ((0.35355338f * fRec132[0]) + 1e-20f);
			float fTemp147 = (((0.6f * fRec130[1]) + fVec16[(IOTA-iConst168)&32767]) - fTemp139);
			fVec17[IOTA&2047] = fTemp147;
			fRec130[0] = fVec17[(IOTA-iConst169)&2047];
			float 	fRec131 = (0 - (0.6f * fVec17[IOTA&2047]));
			float fTemp148 = (fRec130[1] + fRec131);
			float fTemp149 = (fRec127 + (fRec126[1] + fTemp148));
			float fTemp150 = (fRec119 + (fRec118[1] + (fRec123 + (fRec122[1] + fTemp149))));
			fRec0[0] = (fRec9 + (fRec8[1] + (fRec107 + (fRec106[1] + (fRec111 + (fRec110[1] + (fRec115 + (fRec114[1] + fTemp150))))))));
			fRec1[0] = ((fRec9 + (fRec8[1] + (fRec107 + (fRec106[1] + (fRec111 + (fRec110[1] + (fRec114[1] + fRec115))))))) - fTemp150);
			float fTemp151 = (fRec119 + (fRec118[1] + (fRec122[1] + fRec123)));
			fRec2[0] = ((fRec9 + (fRec8[1] + (fRec107 + (fRec106[1] + fTemp151)))) - (fRec111 + (fRec110[1] + (fRec115 + (fRec114[1] + fTemp149)))));
			fRec3[0] = ((fRec9 + (fRec8[1] + (fRec107 + (fRec106[1] + fTemp149)))) - (fRec111 + (fRec110[1] + (fRec115 + (fRec114[1] + fTemp151)))));
			float fTemp152 = (fRec126[1] + fRec127);
			float fTemp153 = (fRec119 + (fRec118[1] + fTemp152));
			float fTemp154 = (fRec123 + (fRec122[1] + fTemp148));
			fRec4[0] = ((fRec9 + (fRec8[1] + (fRec111 + (fRec110[1] + fTemp153)))) - (fRec107 + (fRec106[1] + (fRec115 + (fRec114[1] + fTemp154)))));
			fRec5[0] = ((fRec9 + (fRec8[1] + (fRec111 + (fRec110[1] + fTemp154)))) - (fRec107 + (fRec106[1] + (fRec115 + (fRec114[1] + fTemp153)))));
			float fTemp155 = (fRec119 + (fRec118[1] + fTemp148));
			float fTemp156 = (fRec123 + (fRec122[1] + fTemp152));
			fRec6[0] = ((fRec9 + (fRec8[1] + (fRec115 + (fRec114[1] + fTemp155)))) - (fRec107 + (fRec106[1] + (fRec111 + (fRec110[1] + fTemp156)))));
			fRec7[0] = ((fRec9 + (fRec8[1] + (fRec115 + (fRec114[1] + fTemp156)))) - (fRec107 + (fRec106[1] + (fRec111 + (fRec110[1] + fTemp155)))));
			fRec134[0] = (fSlow12 + (fConst170 * fRec134[1]));
			float fTemp157 = ((1 - fRec134[0]) * fTemp138);
			output0[i] = (FAUSTFLOAT)((0.185f * ((fRec1[0] + fRec2[0]) * fRec134[0])) + fTemp157);
			output1[i] = (FAUSTFLOAT)((0.185f * (fRec134[0] * (fRec1[0] - fRec2[0]))) + fTemp157);
			// post processing
			fRec134[1] = fRec134[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec130[1] = fRec130[0];
			fRec132[1] = fRec132[0];
			fRec133[1] = fRec133[0];
			fRec126[1] = fRec126[0];
			fRec128[1] = fRec128[0];
			fRec129[1] = fRec129[0];
			fRec122[1] = fRec122[0];
			fRec124[1] = fRec124[0];
			fRec125[1] = fRec125[0];
			fRec118[1] = fRec118[0];
			fRec120[1] = fRec120[0];
			fRec121[1] = fRec121[0];
			fRec114[1] = fRec114[0];
			fRec116[1] = fRec116[0];
			fRec117[1] = fRec117[0];
			fRec110[1] = fRec110[0];
			fRec112[1] = fRec112[0];
			fRec113[1] = fRec113[0];
			fRec106[1] = fRec106[0];
			fRec108[1] = fRec108[0];
			fRec109[1] = fRec109[0];
			fRec8[1] = fRec8[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec83[2] = fRec83[1]; fRec83[1] = fRec83[0];
			fRec84[2] = fRec84[1]; fRec84[1] = fRec84[0];
			fRec104[2] = fRec104[1]; fRec104[1] = fRec104[0];
			fRec105[2] = fRec105[1]; fRec105[1] = fRec105[0];
			fRec103[1] = fRec103[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec97[2] = fRec97[1]; fRec97[1] = fRec97[0];
			fRec98[2] = fRec98[1]; fRec98[1] = fRec98[0];
			iRec99[1] = iRec99[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec82[1] = fRec82[0];
			fRec79[1] = fRec79[0];
			fRec78[1] = fRec78[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec77[1] = fRec77[0];
			fRec76[1] = fRec76[0];
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec26[1] = fRec26[0];
			fRec25[1] = fRec25[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec13[1] = fRec13[0];
			IOTA = IOTA+1;
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			iVec0[1] = iVec0[0];
		}
	}
};


#endif
