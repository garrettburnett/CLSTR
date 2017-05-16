/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "EchoChamber.h"



//==============================================================================
/**
*/
class NewProjectAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    NewProjectAudioProcessor();
    ~NewProjectAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
  
    
    float getBPM();
    
    
    AudioPlayHead* playHead;
    
    AudioPlayHead::CurrentPositionInfo currentPositionInfo;
    
    
    AudioParameterFloat* wetMixParameter;//index 0
    float wetMix;
    AudioParameterFloat* dryMixParameter;
    float dryMix;
    
    AudioParameterFloat* delayParameters[8];
    
    float delayGain[8];
    

private:
    
    const static int numDelays = 8;
    EchoChamber echos[numDelays];   //an array of echos.
    
    float* delayData[numDelays];
   
    void syncBPM();
    void rwIn(int _channel);
    
    void rwOut(float _in);
    
    void rwClean();
    
    float effectOut(float _in);

   
    
    
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessor)
};
