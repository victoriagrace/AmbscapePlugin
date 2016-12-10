/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

#define NUMFRAMES 64

//==============================================================================
/**
*/
class AmbscapePluginAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    AmbscapePluginAudioProcessorEditor (AmbscapePluginAudioProcessor&);
    ~AmbscapePluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
//    void repaint (Graphics&) ;

    void resized() override;
    
    void mouseDown(const MouseEvent &evt);
    void mouseUp(const MouseEvent &evt);

    void mouseDrag(const MouseEvent &evt);
    float xPos;
    float yPos;
    float xPos2;
    float yPos2;
    
    float xPosChord;
    float yPosChord;
    float yPosLead;
    
    float soprano;
    float alto;
    float tenor;
    float bass;
    
    
    Image juceImage[NUMFRAMES];
    Image juceImagePress[NUMFRAMES];
    

private:
    float pull;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AmbscapePluginAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmbscapePluginAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
