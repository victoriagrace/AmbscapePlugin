/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AmbscapePluginAudioProcessorEditor::AmbscapePluginAudioProcessorEditor (AmbscapePluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 500);
}

AmbscapePluginAudioProcessorEditor::~AmbscapePluginAudioProcessorEditor()
{
}

//==============================================================================
void AmbscapePluginAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
    
}

void AmbscapePluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void AmbscapePluginAudioProcessorEditor::mouseDown(const MouseEvent &evt)
{
    processor.setParam("/fm/gate", 1);
}

void AmbscapePluginAudioProcessorEditor::mouseUp(const MouseEvent &evt)
{
    processor.setParam("/fm/gate", 0);

}
void AmbscapePluginAudioProcessorEditor::mouseDrag(const MouseEvent &evt)
{
    Rectangle<int> area = getScreenBounds();
    float x =(float) evt.getDistanceFromDragStartX() / area.getWidth();
    float y =(float) evt.getDistanceFromDragStartY() / area.getHeight();
    
    float pull = sqrtf(x*x + y*y);
    float rot;
    if (x == 0) {
        rot = 0;
    } else {
        rot = atan(y/x)/ (M_PI / 2.0);
        rot= (rot+1.0)*0.5;
        
    }
    
    processor.setParam("/fm/pull",pull);
    processor.setParam("/fm/rotation",rot);
    
    
    
}