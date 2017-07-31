/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "PluginProcessor.h"
#include "CLSTRLookAndFeel.h"


#include <string>
using namespace std;


class MainTab  : public TabbedComponent
{
public:
    
    MainTab (AudioProcessor& p)
    : TabbedComponent (TabbedButtonBar::TabsAtBottom)
    {
       
    }
};


//==============================================================================
/**
*/
class NewProjectAudioProcessorEditor  : public AudioProcessorEditor, private Slider::Listener,public Timer
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void timerCallback(); //to update UI sliders


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    NewProjectAudioProcessor& processor;
    void sliderValueChanged (Slider* slider) override;
    AudioParameterFloat* getParameterForSlider (Slider* slider);
    
    CLSTRLookAndFeel laf;
    CLSTRLookAndFeel2 laf2;
    

    //UI COMPONENTS//
    
    Slider wetMixSlider;
    Slider dryMixSlider;
    
    MainTab mt;
    
    
    //Sliders for separate effects//
    
    Slider delaysWet[8];
    Slider pan[8];

    NewProjectAudioProcessor* getProcessor() const
    {
        return static_cast <NewProjectAudioProcessor*> (getAudioProcessor());
    }

};








