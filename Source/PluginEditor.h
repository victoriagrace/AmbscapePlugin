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
    void resized() override;
    
    void mouseDown(const MouseEvent &evt);
    void mouseUp(const MouseEvent &evt);

    void mouseDrag(const MouseEvent &evt);
    float xPos;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AmbscapePluginAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmbscapePluginAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
