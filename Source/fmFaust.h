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
	int 	iVec0[2];
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
	float 	fConst11;
	float 	fConst12;
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	float 	fRec11[2];
	float 	fRec10[2];
	int 	IOTA;
	float 	fVec1[32768];
	float 	fConst17;
	int 	iConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fConst24;
	float 	fConst25;
	FAUSTFLOAT 	fcheckbox0;
	float 	fRec13[2];
	float 	fConst26;
	FAUSTFLOAT 	fslider0;
	float 	fRec16[2];
	float 	fConst27;
	float 	fRec17[2];
	float 	fRec18[2];
	float 	fConst28;
	float 	fConst29;
	float 	fConst30;
	float 	fRec19[2];
	float 	fConst31;
	float 	fRec20[2];
	FAUSTFLOAT 	fslider1;
	float 	fRec21[2];
	FAUSTFLOAT 	fslider2;
	float 	fRec22[2];
	float 	fRec14[2];
	float 	fRec15[2];
	float 	fConst32;
	float 	fRec25[2];
	float 	fRec26[2];
	float 	fRec23[2];
	float 	fRec24[2];
	float 	fConst33;
	float 	fRec29[2];
	float 	fRec30[2];
	float 	fRec27[2];
	float 	fRec28[2];
	FAUSTFLOAT 	fslider3;
	float 	fRec33[2];
	float 	fRec34[2];
	float 	fRec35[2];
	float 	fRec31[2];
	float 	fRec32[2];
	float 	fRec38[2];
	float 	fRec39[2];
	float 	fRec36[2];
	float 	fRec37[2];
	float 	fRec42[2];
	float 	fRec43[2];
	float 	fRec40[2];
	float 	fRec41[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec46[2];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec44[2];
	float 	fRec45[2];
	float 	fRec51[2];
	float 	fRec52[2];
	float 	fRec49[2];
	float 	fRec50[2];
	float 	fRec55[2];
	float 	fRec56[2];
	float 	fRec53[2];
	float 	fRec54[2];
	FAUSTFLOAT 	fslider5;
	float 	fRec59[2];
	float 	fRec60[2];
	float 	fRec61[2];
	float 	fRec57[2];
	float 	fRec58[2];
	float 	fRec64[2];
	float 	fRec65[2];
	float 	fRec62[2];
	float 	fRec63[2];
	float 	fRec68[2];
	float 	fRec69[2];
	float 	fRec66[2];
	float 	fRec67[2];
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
	float 	fConst34;
	float 	fConst35;
	float 	fConst36;
	float 	fConst37;
	float 	fConst38;
	float 	fConst39;
	float 	fConst40;
	float 	fConst41;
	float 	fConst42;
	float 	fConst43;
	FAUSTFLOAT 	fslider6;
	float 	fRec86[2];
	float 	fRec84[2];
	float 	fRec85[2];
	float 	fRec87[2];
	float 	fRec88[2];
	float 	fConst44;
	int 	iRec91[2];
	float 	fRec90[3];
	float 	fRec89[3];
	float 	fRec93[3];
	float 	fRec92[3];
	float 	fConst45;
	float 	fConst46;
	float 	fConst47;
	float 	fRec96[2];
	float 	fConst48;
	float 	fRec97[2];
	float 	fConst49;
	float 	fConst50;
	float 	fConst51;
	float 	fRec98[2];
	float 	fConst52;
	float 	fRec99[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec100[2];
	float 	fConst53;
	float 	fRec101[2];
	float 	fRec102[2];
	float 	fRec94[2];
	float 	fRec95[2];
	float 	fConst54;
	float 	fConst55;
	float 	fRec83[3];
	float 	fConst56;
	float 	fConst57;
	float 	fConst58;
	float 	fConst59;
	float 	fRec82[3];
	float 	fConst60;
	float 	fConst61;
	float 	fRec103[2];
	float 	fConst62;
	float 	fConst63;
	float 	fConst64;
	float 	fRec12[3];
	float 	fConst65;
	float 	fVec2[2048];
	int 	iConst66;
	float 	fVec3[4096];
	int 	iConst67;
	float 	fRec8[2];
	float 	fConst68;
	float 	fConst69;
	float 	fConst70;
	float 	fConst71;
	float 	fConst72;
	float 	fConst73;
	float 	fConst74;
	float 	fConst75;
	float 	fConst76;
	float 	fConst77;
	float 	fConst78;
	float 	fRec107[2];
	float 	fRec106[2];
	float 	fVec4[32768];
	float 	fConst79;
	int 	iConst80;
	float 	fVec5[2048];
	int 	iConst81;
	float 	fRec104[2];
	float 	fConst82;
	float 	fConst83;
	float 	fConst84;
	float 	fConst85;
	float 	fConst86;
	float 	fConst87;
	float 	fConst88;
	float 	fConst89;
	float 	fConst90;
	float 	fConst91;
	float 	fConst92;
	float 	fRec111[2];
	float 	fRec110[2];
	float 	fVec6[16384];
	float 	fConst93;
	int 	iConst94;
	float 	fVec7[2048];
	int 	iConst95;
	float 	fRec108[2];
	float 	fConst96;
	float 	fConst97;
	float 	fConst98;
	float 	fConst99;
	float 	fConst100;
	float 	fConst101;
	float 	fConst102;
	float 	fConst103;
	float 	fConst104;
	float 	fConst105;
	float 	fConst106;
	float 	fRec115[2];
	float 	fRec114[2];
	float 	fVec8[32768];
	float 	fConst107;
	int 	iConst108;
	float 	fVec9[4096];
	int 	iConst109;
	float 	fRec112[2];
	float 	fConst110;
	float 	fConst111;
	float 	fConst112;
	float 	fConst113;
	float 	fConst114;
	float 	fConst115;
	float 	fConst116;
	float 	fConst117;
	float 	fConst118;
	float 	fConst119;
	float 	fConst120;
	float 	fRec119[2];
	float 	fRec118[2];
	float 	fVec10[16384];
	float 	fConst121;
	int 	iConst122;
	float 	fVec11[4096];
	int 	iConst123;
	float 	fRec116[2];
	float 	fConst124;
	float 	fConst125;
	float 	fConst126;
	float 	fConst127;
	float 	fConst128;
	float 	fConst129;
	float 	fConst130;
	float 	fConst131;
	float 	fConst132;
	float 	fConst133;
	float 	fConst134;
	float 	fRec123[2];
	float 	fRec122[2];
	float 	fVec12[16384];
	float 	fConst135;
	int 	iConst136;
	float 	fVec13[2048];
	int 	iConst137;
	float 	fRec120[2];
	float 	fConst138;
	float 	fConst139;
	float 	fConst140;
	float 	fConst141;
	float 	fConst142;
	float 	fConst143;
	float 	fConst144;
	float 	fConst145;
	float 	fConst146;
	float 	fConst147;
	float 	fConst148;
	float 	fRec127[2];
	float 	fRec126[2];
	float 	fVec14[16384];
	float 	fConst149;
	int 	iConst150;
	float 	fVec15[4096];
	int 	iConst151;
	float 	fRec124[2];
	float 	fConst152;
	float 	fConst153;
	float 	fConst154;
	float 	fConst155;
	float 	fConst156;
	float 	fConst157;
	float 	fConst158;
	float 	fConst159;
	float 	fConst160;
	float 	fConst161;
	float 	fConst162;
	float 	fRec131[2];
	float 	fRec130[2];
	float 	fVec16[16384];
	float 	fConst163;
	int 	iConst164;
	float 	fVec17[4096];
	int 	iConst165;
	float 	fRec128[2];
	float 	fRec0[3];
	float 	fRec1[3];
	float 	fRec2[3];
	float 	fRec3[3];
	float 	fRec4[3];
	float 	fRec5[3];
	float 	fRec6[3];
	float 	fRec7[3];
	float 	fConst166;
	float 	fConst167;
	float 	fRec132[2];
	int fSamplingFreq;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("math.lib/name", "Faust Math Library");
		m->declare("math.lib/version", "2.0");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("noise.lib/name", "Faust Noise Generator Library");
		m->declare("noise.lib/version", "0.0");
		m->declare("miscoscillator.lib/name", "Faust Oscillator Library");
		m->declare("miscoscillator.lib/version", "0.0");
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/version", "2.0");
		m->declare("oscillator.lib/name", "Faust Oscillator Library");
		m->declare("oscillator.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("oscillator.lib/copyright", "Julius O. Smith III");
		m->declare("oscillator.lib/version", "1.11");
		m->declare("oscillator.lib/license", "STK-4.3");
		m->declare("oscillator.lib/deprecated", "This library is deprecated and is not maintained anymore. It might be removed in future released.");
		m->declare("signal.lib/name", "Faust Signal Routing Library");
		m->declare("signal.lib/version", "0.0");
		m->declare("basic.lib/name", "Faust Basic Element Library");
		m->declare("basic.lib/version", "0.0");
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
		fConst2 = floorf(((0.256891f * fConst0) + 0.5f));
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
		fConst17 = floorf(((0.027333f * fConst0) + 0.5f));
		iConst18 = int((int((fConst2 - fConst17)) & 32767));
		fConst19 = tanf((188.49556f / fConst0));
		fConst20 = (1.0f / fConst19);
		fConst21 = (((fConst20 + 1.4142135f) / fConst19) + 1);
		fConst22 = (0.3f / fConst21);
		fConst23 = (1.0f / faustpower<2>(fConst19));
		fConst24 = expf((0 - (0.6666667f / fConst0)));
		fConst25 = (1.0f - fConst24);
		fConst26 = (6.2831855f / fConst0);
		fConst27 = (2764.3252f / fConst0);
		fConst28 = (0.41887903f / fConst0);
		fConst29 = sinf(fConst28);
		fConst30 = cosf(fConst28);
		fConst31 = (0 - fConst29);
		fConst32 = (2764.878f / fConst0);
		fConst33 = (2764.6016f / fConst0);
		fConst34 = tanf((12566.371f / fConst0));
		fConst35 = (1.0f / fConst34);
		fConst36 = (((fConst35 + 1.4142135f) / fConst34) + 1);
		fConst37 = (0.3548134f / fConst36);
		fConst38 = tanf((3141.5928f / fConst0));
		fConst39 = (1.0f / fConst38);
		fConst40 = (1.0f / (((fConst39 + 1.4142135f) / fConst38) + 1));
		fConst41 = (1.0f / faustpower<2>(fConst38));
		fConst42 = expf((0 - (12.5f / fConst0)));
		fConst43 = (1.0f - fConst42);
		fConst44 = (1382.3008f / fConst0);
		fConst45 = (37.699112f / fConst0);
		fConst46 = sinf(fConst45);
		fConst47 = cosf(fConst45);
		fConst48 = (0 - fConst46);
		fConst49 = (18.912388f / fConst0);
		fConst50 = sinf(fConst49);
		fConst51 = cosf(fConst49);
		fConst52 = (0 - fConst50);
		fConst53 = (5529.203f / fConst0);
		fConst54 = (2 * (1 - fConst41));
		fConst55 = (((fConst39 + -1.4142135f) / fConst38) + 1);
		fConst56 = (2 * (0 - fConst41));
		fConst57 = (1.0f / fConst36);
		fConst58 = (2 * (1 - (1.0f / faustpower<2>(fConst34))));
		fConst59 = (((fConst35 + -1.4142135f) / fConst34) + 1);
		fConst60 = expf((0 - (2.2222223f / fConst0)));
		fConst61 = (1.0f - fConst60);
		fConst62 = (1.0f / fConst21);
		fConst63 = (((fConst20 + -1.4142135f) / fConst19) + 1);
		fConst64 = (2 * (1 - fConst23));
		fConst65 = (2 * (0 - fConst23));
		iConst66 = int((int((0.01f * fConst0)) & 8191));
		iConst67 = int((int((fConst17 + -1)) & 4095));
		fConst68 = floorf(((0.219991f * fConst0) + 0.5f));
		fConst69 = ((0 - (6.9077554f * fConst68)) / fConst0);
		fConst70 = expf((0.125f * fConst69));
		fConst71 = faustpower<2>(fConst70);
		fConst72 = (1.0f - (fConst71 * fConst1));
		fConst73 = (1.0f - fConst71);
		fConst74 = (fConst72 / fConst73);
		fConst75 = sqrtf(max((float)0, ((faustpower<2>(fConst72) / faustpower<2>(fConst73)) + -1.0f)));
		fConst76 = (fConst74 - fConst75);
		fConst77 = (fConst70 * (fConst75 + (1.0f - fConst74)));
		fConst78 = ((expf((0.16666667f * fConst69)) / fConst70) + -1);
		fConst79 = floorf(((0.019123f * fConst0) + 0.5f));
		iConst80 = int((int((fConst68 - fConst79)) & 32767));
		iConst81 = int((int((fConst79 + -1)) & 2047));
		fConst82 = floorf(((0.125f * fConst0) + 0.5f));
		fConst83 = ((0 - (6.9077554f * fConst82)) / fConst0);
		fConst84 = expf((0.125f * fConst83));
		fConst85 = faustpower<2>(fConst84);
		fConst86 = (1.0f - (fConst1 * fConst85));
		fConst87 = (1.0f - fConst85);
		fConst88 = (fConst86 / fConst87);
		fConst89 = sqrtf(max((float)0, ((faustpower<2>(fConst86) / faustpower<2>(fConst87)) + -1.0f)));
		fConst90 = (fConst88 - fConst89);
		fConst91 = ((fConst89 + (1.0f - fConst88)) * fConst84);
		fConst92 = ((expf((0.16666667f * fConst83)) / fConst84) + -1);
		fConst93 = floorf(((0.013458f * fConst0) + 0.5f));
		iConst94 = int((int((fConst82 - fConst93)) & 16383));
		iConst95 = int((int((fConst93 + -1)) & 2047));
		fConst96 = floorf(((0.210389f * fConst0) + 0.5f));
		fConst97 = ((0 - (6.9077554f * fConst96)) / fConst0);
		fConst98 = expf((0.125f * fConst97));
		fConst99 = faustpower<2>(fConst98);
		fConst100 = (1.0f - (fConst1 * fConst99));
		fConst101 = (1.0f - fConst99);
		fConst102 = (fConst100 / fConst101);
		fConst103 = sqrtf(max((float)0, ((faustpower<2>(fConst100) / faustpower<2>(fConst101)) + -1.0f)));
		fConst104 = (fConst102 - fConst103);
		fConst105 = (fConst98 * (fConst103 + (1.0f - fConst102)));
		fConst106 = ((expf((0.16666667f * fConst97)) / fConst98) + -1);
		fConst107 = floorf(((0.024421f * fConst0) + 0.5f));
		iConst108 = int((int((fConst96 - fConst107)) & 32767));
		iConst109 = int((int((fConst107 + -1)) & 4095));
		fConst110 = floorf(((0.192303f * fConst0) + 0.5f));
		fConst111 = ((0 - (6.9077554f * fConst110)) / fConst0);
		fConst112 = expf((0.125f * fConst111));
		fConst113 = faustpower<2>(fConst112);
		fConst114 = (1.0f - (fConst1 * fConst113));
		fConst115 = (1.0f - fConst113);
		fConst116 = (fConst114 / fConst115);
		fConst117 = sqrtf(max((float)0, ((faustpower<2>(fConst114) / faustpower<2>(fConst115)) + -1.0f)));
		fConst118 = (fConst116 - fConst117);
		fConst119 = (fConst112 * (fConst117 + (1.0f - fConst116)));
		fConst120 = ((expf((0.16666667f * fConst111)) / fConst112) + -1);
		fConst121 = floorf(((0.029291f * fConst0) + 0.5f));
		iConst122 = int((int((fConst110 - fConst121)) & 16383));
		iConst123 = int((int((fConst121 + -1)) & 4095));
		fConst124 = floorf(((0.153129f * fConst0) + 0.5f));
		fConst125 = ((0 - (6.9077554f * fConst124)) / fConst0);
		fConst126 = expf((0.125f * fConst125));
		fConst127 = faustpower<2>(fConst126);
		fConst128 = (1.0f - (fConst1 * fConst127));
		fConst129 = (1.0f - fConst127);
		fConst130 = (fConst128 / fConst129);
		fConst131 = sqrtf(max((float)0, ((faustpower<2>(fConst128) / faustpower<2>(fConst129)) + -1.0f)));
		fConst132 = (fConst130 - fConst131);
		fConst133 = (fConst126 * (fConst131 + (1.0f - fConst130)));
		fConst134 = ((expf((0.16666667f * fConst125)) / fConst126) + -1);
		fConst135 = floorf(((0.020346f * fConst0) + 0.5f));
		iConst136 = int((int((fConst124 - fConst135)) & 16383));
		iConst137 = int((int((fConst135 + -1)) & 2047));
		fConst138 = floorf(((0.174713f * fConst0) + 0.5f));
		fConst139 = ((0 - (6.9077554f * fConst138)) / fConst0);
		fConst140 = expf((0.125f * fConst139));
		fConst141 = faustpower<2>(fConst140);
		fConst142 = (1.0f - (fConst1 * fConst141));
		fConst143 = (1.0f - fConst141);
		fConst144 = (fConst142 / fConst143);
		fConst145 = sqrtf(max((float)0, ((faustpower<2>(fConst142) / faustpower<2>(fConst143)) + -1.0f)));
		fConst146 = (fConst144 - fConst145);
		fConst147 = (fConst140 * (fConst145 + (1.0f - fConst144)));
		fConst148 = ((expf((0.16666667f * fConst139)) / fConst140) + -1);
		fConst149 = floorf(((0.022904f * fConst0) + 0.5f));
		iConst150 = int((int((fConst138 - fConst149)) & 16383));
		iConst151 = int((int((fConst149 + -1)) & 4095));
		fConst152 = floorf(((0.127837f * fConst0) + 0.5f));
		fConst153 = ((0 - (6.9077554f * fConst152)) / fConst0);
		fConst154 = expf((0.125f * fConst153));
		fConst155 = faustpower<2>(fConst154);
		fConst156 = (1.0f - (fConst1 * fConst155));
		fConst157 = (1.0f - fConst155);
		fConst158 = (fConst156 / fConst157);
		fConst159 = sqrtf(max((float)0, ((faustpower<2>(fConst156) / faustpower<2>(fConst157)) + -1.0f)));
		fConst160 = (fConst158 - fConst159);
		fConst161 = (fConst154 * (fConst159 + (1.0f - fConst158)));
		fConst162 = ((expf((0.16666667f * fConst153)) / fConst154) + -1);
		fConst163 = floorf(((0.031604f * fConst0) + 0.5f));
		iConst164 = int((int((fConst152 - fConst163)) & 16383));
		iConst165 = int((int((fConst163 + -1)) & 4095));
		fConst166 = expf((0 - (1.0f / fConst0)));
		fConst167 = (1.0f - fConst166);
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
		for (int i=0; i<32768; i++) fVec1[i] = 0;
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
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
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
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) iRec91[i] = 0;
		for (int i=0; i<3; i++) fRec90[i] = 0;
		for (int i=0; i<3; i++) fRec89[i] = 0;
		for (int i=0; i<3; i++) fRec93[i] = 0;
		for (int i=0; i<3; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<3; i++) fRec83[i] = 0;
		for (int i=0; i<3; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<2048; i++) fVec2[i] = 0;
		for (int i=0; i<4096; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<32768; i++) fVec4[i] = 0;
		for (int i=0; i<2048; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<16384; i++) fVec6[i] = 0;
		for (int i=0; i<2048; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec115[i] = 0;
		for (int i=0; i<2; i++) fRec114[i] = 0;
		for (int i=0; i<32768; i++) fVec8[i] = 0;
		for (int i=0; i<4096; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		for (int i=0; i<2; i++) fRec118[i] = 0;
		for (int i=0; i<16384; i++) fVec10[i] = 0;
		for (int i=0; i<4096; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec116[i] = 0;
		for (int i=0; i<2; i++) fRec123[i] = 0;
		for (int i=0; i<2; i++) fRec122[i] = 0;
		for (int i=0; i<16384; i++) fVec12[i] = 0;
		for (int i=0; i<2048; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<2; i++) fRec127[i] = 0;
		for (int i=0; i<2; i++) fRec126[i] = 0;
		for (int i=0; i<16384; i++) fVec14[i] = 0;
		for (int i=0; i<4096; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
		for (int i=0; i<2; i++) fRec131[i] = 0;
		for (int i=0; i<2; i++) fRec130[i] = 0;
		for (int i=0; i<16384; i++) fVec16[i] = 0;
		for (int i=0; i<4096; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec128[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec132[i] = 0;
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
		ui_interface->addHorizontalSlider("alto", &fslider3, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("bass", &fslider0, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addCheckButton("gate", &fcheckbox0);
		ui_interface->addHorizontalSlider("indx", &fslider1, 1.0f, 0.0f, 2e+01f, 0.01f);
		ui_interface->addHorizontalSlider("lead", &fslider6, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("pull", &fslider2, 0.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->addHorizontalSlider("rotation", &fslider7, 0.0f, 0.0f, 1.0f, 0.001f);
		ui_interface->addHorizontalSlider("soprano", &fslider4, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->addHorizontalSlider("tenor", &fslider5, 69.0f, 12.0f, 1e+02f, 1.0f);
		ui_interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		float 	fSlow0 = float(fcheckbox0);
		float 	fSlow1 = (fConst25 * fSlow0);
		float 	fSlow2 = (0.001f * float(fslider0));
		float 	fSlow3 = (0.001f * float(fslider1));
		float 	fSlow4 = float(fslider2);
		float 	fSlow5 = (0.001f * fSlow4);
		float 	fSlow6 = (0.001f * float(fslider3));
		float 	fSlow7 = (0.001f * float(fslider4));
		float 	fSlow8 = (0.001f * float(fslider5));
		float 	fSlow9 = (fConst43 * float(fslider6));
		float 	fSlow10 = (0.001f * float(fslider7));
		float 	fSlow11 = (fConst61 * fSlow0);
		float 	fSlow12 = (fConst167 * fSlow4);
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			fRec11[0] = ((fConst15 * (fRec3[1] + fRec3[2])) + (fConst16 * fRec11[1]));
			fRec10[0] = ((fConst10 * fRec10[1]) + (fConst11 * (fRec3[1] + (fConst12 * fRec11[0]))));
			fVec1[IOTA&32767] = ((0.35355338f * fRec10[0]) + 1e-20f);
			fRec13[0] = (fSlow1 + (fConst24 * fRec13[1]));
			fRec16[0] = (fSlow2 + (0.999f * fRec16[1]));
			float fTemp0 = powf(2.0f,(0.083333336f * (fRec16[0] + -69.001f)));
			float fTemp1 = (fConst27 * fTemp0);
			float fTemp2 = sinf(fTemp1);
			float fTemp3 = cosf(fTemp1);
			fRec17[0] = ((fRec18[1] * fTemp2) + (fRec17[1] * fTemp3));
			int iTemp4 = (1 - iVec0[1]);
			fRec18[0] = (((fRec18[1] * fTemp3) + (fRec17[1] * (0 - fTemp2))) + iTemp4);
			fRec19[0] = ((fConst29 * fRec20[1]) + (fConst30 * fRec19[1]));
			fRec20[0] = (((fConst30 * fRec20[1]) + (fConst31 * fRec19[1])) + iTemp4);
			float fTemp5 = (fRec19[0] + 1);
			float fTemp6 = (0.25f * fTemp5);
			fRec21[0] = (fSlow3 + (0.999f * fRec21[1]));
			fRec22[0] = (fSlow5 + (0.999f * fRec22[1]));
			float fTemp7 = (3 * fRec22[0]);
			float fTemp8 = (fRec21[0] + fTemp7);
			float fTemp9 = (fConst26 * (fTemp0 * ((439.956f * (fRec17[0] * (fTemp6 + (4.04f * fTemp8)))) + 4.4e+02f)));
			float fTemp10 = sinf(fTemp9);
			float fTemp11 = cosf(fTemp9);
			fRec14[0] = ((fRec15[1] * fTemp10) + (fRec14[1] * fTemp11));
			fRec15[0] = (((fRec15[1] * fTemp11) + (fRec14[1] * (0 - fTemp10))) + iTemp4);
			float fTemp12 = powf(2.0f,(0.083333336f * (fRec16[0] + -68.9f)));
			float fTemp13 = (fConst32 * fTemp12);
			float fTemp14 = sinf(fTemp13);
			float fTemp15 = cosf(fTemp13);
			fRec25[0] = ((fRec26[1] * fTemp14) + (fRec25[1] * fTemp15));
			fRec26[0] = (((fRec26[1] * fTemp15) + (fRec25[1] * (0 - fTemp14))) + iTemp4);
			float fTemp16 = (fConst26 * (fTemp12 * ((440.044f * (fRec25[0] * ((fRec19[0] + (4 * fTemp8)) + 1))) + 4.4e+02f)));
			float fTemp17 = sinf(fTemp16);
			float fTemp18 = cosf(fTemp16);
			fRec23[0] = ((fRec24[1] * fTemp17) + (fRec23[1] * fTemp18));
			fRec24[0] = (((fRec24[1] * fTemp18) + (fRec23[1] * (0 - fTemp17))) + iTemp4);
			float fTemp19 = powf(2.0f,(0.083333336f * (fRec16[0] + -69.0f)));
			float fTemp20 = (fConst33 * fTemp19);
			float fTemp21 = sinf(fTemp20);
			float fTemp22 = cosf(fTemp20);
			fRec29[0] = ((fRec30[1] * fTemp21) + (fRec29[1] * fTemp22));
			fRec30[0] = (((fRec30[1] * fTemp22) + (fRec29[1] * (0 - fTemp21))) + iTemp4);
			float fTemp23 = (fConst33 * (fTemp19 * ((fRec29[0] * (fTemp6 + (3.96f * fTemp8))) + 1.0f)));
			float fTemp24 = sinf(fTemp23);
			float fTemp25 = cosf(fTemp23);
			fRec27[0] = ((fRec28[1] * fTemp24) + (fRec27[1] * fTemp25));
			fRec28[0] = (((fRec28[1] * fTemp25) + (fRec27[1] * (0 - fTemp24))) + iTemp4);
			fRec33[0] = (fSlow6 + (0.999f * fRec33[1]));
			float fTemp26 = powf(2.0f,(0.083333336f * (fRec33[0] + -69.001f)));
			float fTemp27 = (fTemp6 + (1.01f * fTemp8));
			float fTemp28 = (fConst27 * fTemp26);
			float fTemp29 = sinf(fTemp28);
			float fTemp30 = cosf(fTemp28);
			fRec34[0] = ((fRec35[1] * fTemp29) + (fRec34[1] * fTemp30));
			fRec35[0] = (((fRec35[1] * fTemp30) + (fRec34[1] * (0 - fTemp29))) + iTemp4);
			float fTemp31 = (fConst26 * (fTemp26 * ((439.956f * (fTemp27 * fRec34[0])) + 4.4e+02f)));
			float fTemp32 = sinf(fTemp31);
			float fTemp33 = cosf(fTemp31);
			fRec31[0] = ((fRec32[1] * fTemp32) + (fRec31[1] * fTemp33));
			fRec32[0] = (((fRec32[1] * fTemp33) + (fRec31[1] * (0 - fTemp32))) + iTemp4);
			float fTemp34 = powf(2.0f,(0.083333336f * (fRec33[0] + -68.9f)));
			float fTemp35 = ((fTemp7 + (fRec19[0] + fRec21[0])) + 1);
			float fTemp36 = (fConst32 * fTemp34);
			float fTemp37 = sinf(fTemp36);
			float fTemp38 = cosf(fTemp36);
			fRec38[0] = ((fRec39[1] * fTemp37) + (fRec38[1] * fTemp38));
			fRec39[0] = (((fRec39[1] * fTemp38) + (fRec38[1] * (0 - fTemp37))) + iTemp4);
			float fTemp39 = (fConst26 * (fTemp34 * ((440.044f * (fTemp35 * fRec38[0])) + 4.4e+02f)));
			float fTemp40 = sinf(fTemp39);
			float fTemp41 = cosf(fTemp39);
			fRec36[0] = ((fRec37[1] * fTemp40) + (fRec36[1] * fTemp41));
			fRec37[0] = (((fRec37[1] * fTemp41) + (fRec36[1] * (0 - fTemp40))) + iTemp4);
			float fTemp42 = powf(2.0f,(0.083333336f * (fRec33[0] + -69.0f)));
			float fTemp43 = (fTemp6 + (0.99f * fTemp8));
			float fTemp44 = (fConst33 * fTemp42);
			float fTemp45 = sinf(fTemp44);
			float fTemp46 = cosf(fTemp44);
			fRec42[0] = ((fRec43[1] * fTemp45) + (fRec42[1] * fTemp46));
			fRec43[0] = (((fRec43[1] * fTemp46) + (fRec42[1] * (0 - fTemp45))) + iTemp4);
			float fTemp47 = (fConst33 * (fTemp42 * ((fTemp43 * fRec42[0]) + 1.0f)));
			float fTemp48 = sinf(fTemp47);
			float fTemp49 = cosf(fTemp47);
			fRec40[0] = ((fRec41[1] * fTemp48) + (fRec40[1] * fTemp49));
			fRec41[0] = (((fRec41[1] * fTemp49) + (fRec40[1] * (0 - fTemp48))) + iTemp4);
			fRec46[0] = (fSlow7 + (0.999f * fRec46[1]));
			float fTemp50 = powf(2.0f,(0.083333336f * (fRec46[0] + -69.001f)));
			float fTemp51 = (fConst27 * fTemp50);
			float fTemp52 = sinf(fTemp51);
			float fTemp53 = cosf(fTemp51);
			fRec47[0] = ((fRec48[1] * fTemp52) + (fRec47[1] * fTemp53));
			fRec48[0] = (((fRec48[1] * fTemp53) + (fRec47[1] * (0 - fTemp52))) + iTemp4);
			float fTemp54 = (fConst26 * (fTemp50 * ((439.956f * (fTemp27 * fRec47[0])) + 4.4e+02f)));
			float fTemp55 = sinf(fTemp54);
			float fTemp56 = cosf(fTemp54);
			fRec44[0] = ((fRec45[1] * fTemp55) + (fRec44[1] * fTemp56));
			fRec45[0] = (((fRec44[1] * (0 - fTemp55)) + (fRec45[1] * fTemp56)) + iTemp4);
			float fTemp57 = powf(2.0f,(0.083333336f * (fRec46[0] + -68.9f)));
			float fTemp58 = (fConst32 * fTemp57);
			float fTemp59 = sinf(fTemp58);
			float fTemp60 = cosf(fTemp58);
			fRec51[0] = ((fRec52[1] * fTemp59) + (fRec51[1] * fTemp60));
			fRec52[0] = (((fRec52[1] * fTemp60) + (fRec51[1] * (0 - fTemp59))) + iTemp4);
			float fTemp61 = (fConst26 * (fTemp57 * ((440.044f * (fTemp35 * fRec51[0])) + 4.4e+02f)));
			float fTemp62 = sinf(fTemp61);
			float fTemp63 = cosf(fTemp61);
			fRec49[0] = ((fRec50[1] * fTemp62) + (fRec49[1] * fTemp63));
			fRec50[0] = (((fRec49[1] * (0 - fTemp62)) + (fRec50[1] * fTemp63)) + iTemp4);
			float fTemp64 = powf(2.0f,(0.083333336f * (fRec46[0] + -69.0f)));
			float fTemp65 = (fConst33 * fTemp64);
			float fTemp66 = sinf(fTemp65);
			float fTemp67 = cosf(fTemp65);
			fRec55[0] = ((fRec56[1] * fTemp66) + (fRec55[1] * fTemp67));
			fRec56[0] = (((fRec56[1] * fTemp67) + (fRec55[1] * (0 - fTemp66))) + iTemp4);
			float fTemp68 = (fConst33 * (fTemp64 * ((fTemp43 * fRec55[0]) + 1.0f)));
			float fTemp69 = sinf(fTemp68);
			float fTemp70 = cosf(fTemp68);
			fRec53[0] = ((fRec54[1] * fTemp69) + (fRec53[1] * fTemp70));
			fRec54[0] = (((fRec53[1] * (0 - fTemp69)) + (fRec54[1] * fTemp70)) + iTemp4);
			fRec59[0] = (fSlow8 + (0.999f * fRec59[1]));
			float fTemp71 = powf(2.0f,(0.083333336f * (fRec59[0] + -68.9f)));
			float fTemp72 = (fConst32 * fTemp71);
			float fTemp73 = sinf(fTemp72);
			float fTemp74 = cosf(fTemp72);
			fRec60[0] = ((fRec61[1] * fTemp73) + (fRec60[1] * fTemp74));
			fRec61[0] = (((fRec61[1] * fTemp74) + (fRec60[1] * (0 - fTemp73))) + iTemp4);
			float fTemp75 = (fConst26 * (fTemp71 * ((440.044f * (fTemp35 * fRec60[0])) + 4.4e+02f)));
			float fTemp76 = sinf(fTemp75);
			float fTemp77 = cosf(fTemp75);
			fRec57[0] = ((fRec58[1] * fTemp76) + (fRec57[1] * fTemp77));
			fRec58[0] = (((fRec58[1] * fTemp77) + (fRec57[1] * (0 - fTemp76))) + iTemp4);
			float fTemp78 = powf(2.0f,(0.083333336f * (fRec59[0] + -69.0f)));
			float fTemp79 = (fConst33 * fTemp78);
			float fTemp80 = sinf(fTemp79);
			float fTemp81 = cosf(fTemp79);
			fRec64[0] = ((fRec65[1] * fTemp80) + (fRec64[1] * fTemp81));
			fRec65[0] = (((fRec65[1] * fTemp81) + (fRec64[1] * (0 - fTemp80))) + iTemp4);
			float fTemp82 = (fConst33 * (fTemp78 * ((fTemp43 * fRec64[0]) + 1.0f)));
			float fTemp83 = sinf(fTemp82);
			float fTemp84 = cosf(fTemp82);
			fRec62[0] = ((fRec63[1] * fTemp83) + (fRec62[1] * fTemp84));
			fRec63[0] = (((fRec63[1] * fTemp84) + (fRec62[1] * (0 - fTemp83))) + iTemp4);
			float fTemp85 = powf(2.0f,(0.083333336f * (fRec59[0] + -69.001f)));
			float fTemp86 = (fConst27 * fTemp85);
			float fTemp87 = cosf(fTemp86);
			float fTemp88 = sinf(fTemp86);
			fRec68[0] = ((fRec68[1] * fTemp87) + (fRec69[1] * fTemp88));
			fRec69[0] = (((fRec69[1] * fTemp87) + (fRec68[1] * (0 - fTemp88))) + iTemp4);
			float fTemp89 = (fConst26 * (fTemp85 * ((439.956f * (fTemp27 * fRec68[0])) + 4.4e+02f)));
			float fTemp90 = sinf(fTemp89);
			float fTemp91 = cosf(fTemp89);
			fRec66[0] = ((fRec67[1] * fTemp90) + (fRec66[1] * fTemp91));
			fRec67[0] = (((fRec66[1] * (0 - fTemp90)) + (fRec67[1] * fTemp91)) + iTemp4);
			float fTemp92 = powf(2.0f,(0.083333336f * (fRec16[0] + -80.9f)));
			float fTemp93 = (fConst32 * fTemp92);
			float fTemp94 = sinf(fTemp93);
			float fTemp95 = cosf(fTemp93);
			fRec72[0] = ((fRec73[1] * fTemp94) + (fRec72[1] * fTemp95));
			fRec73[0] = (((fRec73[1] * fTemp95) + (fRec72[1] * (0 - fTemp94))) + iTemp4);
			float fTemp96 = (fConst26 * (fTemp92 * ((440.044f * (fRec72[0] * fTemp35)) + 4.4e+02f)));
			float fTemp97 = sinf(fTemp96);
			float fTemp98 = cosf(fTemp96);
			fRec70[0] = ((fRec71[1] * fTemp97) + (fRec70[1] * fTemp98));
			fRec71[0] = (((fRec71[1] * fTemp98) + (fRec70[1] * (0 - fTemp97))) + iTemp4);
			float fTemp99 = powf(2.0f,(0.083333336f * (fRec16[0] + -81.001f)));
			float fTemp100 = (fConst27 * fTemp99);
			float fTemp101 = sinf(fTemp100);
			float fTemp102 = cosf(fTemp100);
			fRec76[0] = ((fRec77[1] * fTemp101) + (fRec76[1] * fTemp102));
			fRec77[0] = (((fRec77[1] * fTemp102) + (fRec76[1] * (0 - fTemp101))) + iTemp4);
			float fTemp103 = (fConst26 * (fTemp99 * ((439.956f * (fRec76[0] * fTemp27)) + 4.4e+02f)));
			float fTemp104 = sinf(fTemp103);
			float fTemp105 = cosf(fTemp103);
			fRec74[0] = ((fRec75[1] * fTemp104) + (fRec74[1] * fTemp105));
			fRec75[0] = (((fRec75[1] * fTemp105) + (fRec74[1] * (0 - fTemp104))) + iTemp4);
			float fTemp106 = powf(2.0f,(0.083333336f * (fRec16[0] + -81.0f)));
			float fTemp107 = (fConst33 * fTemp106);
			float fTemp108 = sinf(fTemp107);
			float fTemp109 = cosf(fTemp107);
			fRec80[0] = ((fRec81[1] * fTemp108) + (fRec80[1] * fTemp109));
			fRec81[0] = (((fRec81[1] * fTemp109) + (fRec80[1] * (0 - fTemp108))) + iTemp4);
			float fTemp110 = (fConst33 * (fTemp106 * ((fRec80[0] * fTemp43) + 1.0f)));
			float fTemp111 = sinf(fTemp110);
			float fTemp112 = cosf(fTemp110);
			fRec78[0] = ((fRec79[1] * fTemp111) + (fRec78[1] * fTemp112));
			fRec79[0] = (((fRec79[1] * fTemp112) + (fRec78[1] * (0 - fTemp111))) + iTemp4);
			fRec86[0] = (fSlow9 + (fConst42 * fRec86[1]));
			float fTemp113 = powf(2.0f,(0.083333336f * (fRec86[0] + -69.0f)));
			float fTemp114 = (fConst33 * fTemp113);
			float fTemp115 = sinf(fTemp114);
			float fTemp116 = cosf(fTemp114);
			fRec84[0] = ((fRec85[1] * fTemp115) + (fRec84[1] * fTemp116));
			fRec85[0] = (((fRec85[1] * fTemp116) + (fRec84[1] * (0 - fTemp115))) + iTemp4);
			float fTemp117 = powf(2.0f,(0.083333336f * (fRec86[0] + -57.0f)));
			float fTemp118 = (fConst33 * fTemp117);
			float fTemp119 = sinf(fTemp118);
			float fTemp120 = cosf(fTemp118);
			fRec87[0] = ((fRec88[1] * fTemp119) + (fRec87[1] * fTemp120));
			fRec88[0] = (((fRec88[1] * fTemp120) + (fRec87[1] * (0 - fTemp119))) + iTemp4);
			float fTemp121 = tanf((fConst44 * fTemp113));
			float fTemp122 = (1.0f / fTemp121);
			float fTemp123 = (((fTemp122 + -0.025f) / fTemp121) + 1);
			float fTemp124 = (1 - (1.0f / faustpower<2>(fTemp121)));
			iRec91[0] = ((1103515245 * iRec91[1]) + 12345);
			float fTemp125 = (4.656613e-11f * iRec91[0]);
			float fTemp126 = (((fTemp122 + 0.025f) / fTemp121) + 1);
			fRec90[0] = (fTemp125 - (((fTemp123 * fRec90[2]) + (2 * (fTemp124 * fRec90[1]))) / fTemp126));
			fRec89[0] = (0 - ((((fRec89[2] * fTemp123) + (2 * (fRec89[1] * fTemp124))) - ((fRec90[2] * (0 - (0.8f / fTemp121))) + (0.8f * (fRec90[0] / fTemp121)))) / fTemp126));
			float fTemp127 = tanf((fConst44 * fTemp117));
			float fTemp128 = (1.0f / fTemp127);
			float fTemp129 = (((fTemp128 + -0.025f) / fTemp127) + 1);
			float fTemp130 = (1 - (1.0f / faustpower<2>(fTemp127)));
			float fTemp131 = (((fTemp128 + 0.025f) / fTemp127) + 1);
			fRec93[0] = (fTemp125 - (((2 * (fTemp130 * fRec93[1])) + (fTemp129 * fRec93[2])) / fTemp131));
			fRec92[0] = (0 - ((((fRec92[2] * fTemp129) + (2 * (fRec92[1] * fTemp130))) - ((fRec93[2] * (0 - (0.8f / fTemp127))) + (0.8f * (fRec93[0] / fTemp127)))) / fTemp131));
			fRec96[0] = ((fConst46 * fRec97[1]) + (fConst47 * fRec96[1]));
			fRec97[0] = (((fConst47 * fRec97[1]) + (fConst48 * fRec96[1])) + iTemp4);
			fRec98[0] = ((fConst50 * fRec99[1]) + (fConst51 * fRec98[1]));
			fRec99[0] = (((fConst51 * fRec99[1]) + (fConst52 * fRec98[1])) + iTemp4);
			fRec100[0] = (fSlow10 + (0.999f * fRec100[1]));
			float fTemp132 = powf(2.0f,(0.083333336f * (((0.1f * ((fRec22[0] * fRec96[0]) + (fRec98[0] * fRec100[0]))) + fRec86[0]) + -69.0f)));
			float fTemp133 = (fConst53 * fTemp132);
			float fTemp134 = sinf(fTemp133);
			float fTemp135 = cosf(fTemp133);
			fRec101[0] = ((fTemp134 * fRec102[1]) + (fTemp135 * fRec101[1]));
			fRec102[0] = (((fTemp135 * fRec102[1]) + ((0 - fTemp134) * fRec101[1])) + iTemp4);
			float fTemp136 = (fConst26 * (fTemp132 * ((8.8e+02f * (((0.75f * fTemp5) + 0.1f) * fRec101[0])) + 1.76e+03f)));
			float fTemp137 = sinf(fTemp136);
			float fTemp138 = cosf(fTemp136);
			fRec94[0] = ((fTemp137 * fRec95[1]) + (fTemp138 * fRec94[1]));
			fRec95[0] = ((((0 - fTemp137) * fRec94[1]) + (fTemp138 * fRec95[1])) + iTemp4);
			fRec83[0] = (((((0.2f * (fRec84[0] + fRec87[0])) + (((fRec89[2] * (0 - (0.9f / fTemp121))) + (0.9f * (fRec89[0] / fTemp121))) / fTemp126)) + (((fRec92[2] * (0 - (0.9f / fTemp127))) + (0.9f * (fRec92[0] / fTemp127))) / fTemp131)) + (0.5f * fRec94[0])) - (fConst40 * ((fConst54 * fRec83[1]) + (fConst55 * fRec83[2]))));
			fRec82[0] = ((fConst40 * ((fConst41 * (fRec83[2] + fRec83[0])) + (fConst56 * fRec83[1]))) - (fConst57 * ((fConst58 * fRec82[1]) + (fConst59 * fRec82[2]))));
			fRec103[0] = (fSlow11 + (fConst60 * fRec103[1]));
			float fTemp139 = ((0.09486833f * (fRec13[0] * (fRec14[0] + (fRec23[0] + (fRec27[0] + (fRec31[0] + (fRec36[0] + (fRec40[0] + (fRec44[0] + (fRec49[0] + (fRec53[0] + (fRec57[0] + (fRec62[0] + (fRec66[0] + (fRec70[0] + (fRec74[0] + fRec78[0])))))))))))))))) + (fConst37 * ((fRec22[0] * ((fRec82[2] + (2.0f * fRec82[1])) + fRec82[0])) * fRec103[0])));
			fRec12[0] = (fTemp139 - (fConst62 * ((fConst63 * fRec12[2]) + (fConst64 * fRec12[1]))));
			fVec2[IOTA&2047] = ((fConst23 * (fRec12[2] + fRec12[0])) + (fConst65 * fRec12[1]));
			float fTemp140 = (fConst22 * fVec2[(IOTA-iConst66)&2047]);
			float fTemp141 = (((0.6f * fRec8[1]) + fVec1[(IOTA-iConst18)&32767]) - fTemp140);
			fVec3[IOTA&4095] = fTemp141;
			fRec8[0] = fVec3[(IOTA-iConst67)&4095];
			float 	fRec9 = (0 - (0.6f * fVec3[IOTA&4095]));
			fRec107[0] = ((fConst15 * (fRec7[1] + fRec7[2])) + (fConst16 * fRec107[1]));
			fRec106[0] = ((fConst76 * fRec106[1]) + (fConst77 * (fRec7[1] + (fConst78 * fRec107[0]))));
			fVec4[IOTA&32767] = ((0.35355338f * fRec106[0]) + 1e-20f);
			float fTemp142 = (((0.6f * fRec104[1]) + fVec4[(IOTA-iConst80)&32767]) - fTemp140);
			fVec5[IOTA&2047] = fTemp142;
			fRec104[0] = fVec5[(IOTA-iConst81)&2047];
			float 	fRec105 = (0 - (0.6f * fVec5[IOTA&2047]));
			float fTemp143 = (fRec104[1] + fRec105);
			float fTemp144 = ((fRec8[1] + fTemp143) + fRec9);
			fRec111[0] = ((fConst15 * (fRec6[1] + fRec6[2])) + (fConst16 * fRec111[1]));
			fRec110[0] = ((fConst90 * fRec110[1]) + (fConst91 * (fRec6[1] + (fConst92 * fRec111[0]))));
			fVec6[IOTA&16383] = ((0.35355338f * fRec110[0]) + 1e-20f);
			float fTemp145 = (fVec6[(IOTA-iConst94)&16383] - (fTemp140 + (0.6f * fRec108[1])));
			fVec7[IOTA&2047] = fTemp145;
			fRec108[0] = fVec7[(IOTA-iConst95)&2047];
			float 	fRec109 = (0.6f * fVec7[IOTA&2047]);
			float fTemp146 = ((fTemp144 + fRec108[1]) + fRec109);
			fRec115[0] = ((fConst15 * (fRec1[1] + fRec1[2])) + (fConst16 * fRec115[1]));
			fRec114[0] = ((fConst104 * fRec114[1]) + (fConst105 * (fRec1[1] + (fConst106 * fRec115[0]))));
			fVec8[IOTA&32767] = ((0.35355338f * fRec114[0]) + 1e-20f);
			float fTemp147 = ((fTemp140 + (0.6f * fRec112[1])) + fVec8[(IOTA-iConst108)&32767]);
			fVec9[IOTA&4095] = fTemp147;
			fRec112[0] = fVec9[(IOTA-iConst109)&4095];
			float 	fRec113 = (0 - (0.6f * fVec9[IOTA&4095]));
			fRec119[0] = ((fConst15 * (fRec5[1] + fRec5[2])) + (fConst16 * fRec119[1]));
			fRec118[0] = ((fConst118 * fRec118[1]) + (fConst119 * (fRec5[1] + (fConst120 * fRec119[0]))));
			fVec10[IOTA&16383] = ((0.35355338f * fRec118[0]) + 1e-20f);
			float fTemp148 = ((fTemp140 + (0.6f * fRec116[1])) + fVec10[(IOTA-iConst122)&16383]);
			fVec11[IOTA&4095] = fTemp148;
			fRec116[0] = fVec11[(IOTA-iConst123)&4095];
			float 	fRec117 = (0 - (0.6f * fVec11[IOTA&4095]));
			fRec123[0] = ((fConst15 * (fRec0[1] + fRec0[2])) + (fConst16 * fRec123[1]));
			fRec122[0] = ((fConst132 * fRec122[1]) + (fConst133 * (fRec0[1] + (fConst134 * fRec123[0]))));
			fVec12[IOTA&16383] = ((0.35355338f * fRec122[0]) + 1e-20f);
			float fTemp149 = ((fTemp140 + fVec12[(IOTA-iConst136)&16383]) - (0.6f * fRec120[1]));
			fVec13[IOTA&2047] = fTemp149;
			fRec120[0] = fVec13[(IOTA-iConst137)&2047];
			float 	fRec121 = (0.6f * fVec13[IOTA&2047]);
			fRec127[0] = ((fConst15 * (fRec4[1] + fRec4[2])) + (fConst16 * fRec127[1]));
			fRec126[0] = ((fConst146 * fRec126[1]) + (fConst147 * (fRec4[1] + (fConst148 * fRec127[0]))));
			fVec14[IOTA&16383] = ((0.35355338f * fRec126[0]) + 1e-20f);
			float fTemp150 = ((fTemp140 + fVec14[(IOTA-iConst150)&16383]) - (0.6f * fRec124[1]));
			fVec15[IOTA&4095] = fTemp150;
			fRec124[0] = fVec15[(IOTA-iConst151)&4095];
			float 	fRec125 = (0.6f * fVec15[IOTA&4095]);
			fRec131[0] = ((fConst15 * (fRec2[1] + fRec2[2])) + (fConst16 * fRec131[1]));
			fRec130[0] = ((fConst160 * fRec130[1]) + (fConst161 * (fRec2[1] + (fConst162 * fRec131[0]))));
			fVec16[IOTA&16383] = ((0.35355338f * fRec130[0]) + 1e-20f);
			float fTemp151 = (fVec16[(IOTA-iConst164)&16383] - (fTemp140 + (0.6f * fRec128[1])));
			fVec17[IOTA&4095] = fTemp151;
			fRec128[0] = fVec17[(IOTA-iConst165)&4095];
			float 	fRec129 = (0.6f * fVec17[IOTA&4095]);
			fRec0[0] = ((((((((((fTemp146 + fRec112[1]) + fRec113) + fRec116[1]) + fRec117) + fRec120[1]) + fRec121) + fRec124[1]) + fRec125) + fRec128[1]) + fRec129);
			float fTemp152 = (fRec108[1] + fRec109);
			fRec1[0] = ((((((fRec121 + (fTemp152 + fRec120[1])) + fRec124[1]) + fRec125) + fRec128[1]) + fRec129) - ((((fTemp144 + fRec112[1]) + fRec113) + fRec116[1]) + fRec117));
			fRec2[0] = (((((((fRec116[1] + (fRec112[1] + fRec113)) + fRec117) + fRec120[1]) + fRec121) + fRec124[1]) + fRec125) - ((fTemp146 + fRec128[1]) + fRec129));
			fRec3[0] = (((((fTemp144 + fRec120[1]) + fRec121) + fRec124[1]) + fRec125) - (((((fRec113 + (fTemp152 + fRec112[1])) + fRec116[1]) + fRec117) + fRec128[1]) + fRec129));
			float fTemp153 = (fRec8[1] + fRec9);
			float fTemp154 = ((fRec108[1] + fTemp143) + fRec109);
			fRec4[0] = (((((((fRec112[1] + fTemp153) + fRec113) + fRec120[1]) + fRec121) + fRec128[1]) + fRec129) - (fRec125 + (fRec124[1] + ((fTemp154 + fRec116[1]) + fRec117))));
			float fTemp155 = ((fRec108[1] + fTemp153) + fRec109);
			fRec5[0] = ((fRec129 + (fRec128[1] + (fRec121 + (fRec120[1] + (fRec117 + (fRec116[1] + fTemp143)))))) - (fRec125 + (fRec124[1] + (fRec113 + (fTemp155 + fRec112[1])))));
			fRec6[0] = ((fRec121 + (fRec120[1] + (fRec113 + (fTemp154 + fRec112[1])))) - (fRec129 + (fRec128[1] + (fRec125 + (fRec124[1] + (fRec117 + (fRec116[1] + fTemp153)))))));
			fRec7[0] = ((fRec121 + (fRec120[1] + (fRec117 + (fTemp155 + fRec116[1])))) - (fRec129 + (fRec128[1] + (fRec125 + (fRec124[1] + (fRec113 + (fRec112[1] + fTemp143)))))));
			fRec132[0] = (fSlow12 + (fConst166 * fRec132[1]));
			float fTemp156 = (fTemp139 * (1 - fRec132[0]));
			output0[i] = (FAUSTFLOAT)((0.185f * ((fRec1[0] + fRec2[0]) * fRec132[0])) + fTemp156);
			output1[i] = (FAUSTFLOAT)((0.185f * (fRec132[0] * (fRec1[0] - fRec2[0]))) + fTemp156);
			// post processing
			fRec132[1] = fRec132[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec128[1] = fRec128[0];
			fRec130[1] = fRec130[0];
			fRec131[1] = fRec131[0];
			fRec124[1] = fRec124[0];
			fRec126[1] = fRec126[0];
			fRec127[1] = fRec127[0];
			fRec120[1] = fRec120[0];
			fRec122[1] = fRec122[0];
			fRec123[1] = fRec123[0];
			fRec116[1] = fRec116[0];
			fRec118[1] = fRec118[0];
			fRec119[1] = fRec119[0];
			fRec112[1] = fRec112[0];
			fRec114[1] = fRec114[0];
			fRec115[1] = fRec115[0];
			fRec108[1] = fRec108[0];
			fRec110[1] = fRec110[0];
			fRec111[1] = fRec111[0];
			fRec104[1] = fRec104[0];
			fRec106[1] = fRec106[0];
			fRec107[1] = fRec107[0];
			fRec8[1] = fRec8[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec103[1] = fRec103[0];
			fRec82[2] = fRec82[1]; fRec82[1] = fRec82[0];
			fRec83[2] = fRec83[1]; fRec83[1] = fRec83[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec92[2] = fRec92[1]; fRec92[1] = fRec92[0];
			fRec93[2] = fRec93[1]; fRec93[1] = fRec93[0];
			fRec89[2] = fRec89[1]; fRec89[1] = fRec89[0];
			fRec90[2] = fRec90[1]; fRec90[1] = fRec90[0];
			iRec91[1] = iRec91[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			fRec86[1] = fRec86[0];
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
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec35[1] = fRec35[0];
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
