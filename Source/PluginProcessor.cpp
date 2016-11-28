/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AmbscapePluginAudioProcessor::AmbscapePluginAudioProcessor()
{
}

AmbscapePluginAudioProcessor::~AmbscapePluginAudioProcessor()
{
}

//==============================================================================
const String AmbscapePluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AmbscapePluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AmbscapePluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double AmbscapePluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AmbscapePluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AmbscapePluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AmbscapePluginAudioProcessor::setCurrentProgram (int index)
{
}

const String AmbscapePluginAudioProcessor::getProgramName (int index)
{
    return String();
}

void AmbscapePluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}




//==============================================================================
void AmbscapePluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    synth.init(sampleRate); // initializing the Faust module
    synth.buildUserInterface(&synthControl);
    
    for(int i=0; i<synthControl.getParamsCount(); i++){
        std::cout << synthControl.getParamAdress(i) << "\n";
    }
}

void AmbscapePluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AmbscapePluginAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void AmbscapePluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    float *bufferArray[totalNumOutputChannels];
    
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain i  nput data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumOutputChannels; ++channel)
    {
        bufferArray[channel]  = buffer.getWritePointer (channel); // returns buffer to write to
        // ..do something to the data...
    }
    synth.compute(buffer.getNumSamples(),NULL,bufferArray);
}

//==============================================================================
bool AmbscapePluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AmbscapePluginAudioProcessor::createEditor()
{
    return new AmbscapePluginAudioProcessorEditor (*this);
}

//==============================================================================
void AmbscapePluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AmbscapePluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AmbscapePluginAudioProcessor();
}

void AmbscapePluginAudioProcessor::setParam(const char* path, float value)
{
    synthControl.setParamValue(path,value);
}
