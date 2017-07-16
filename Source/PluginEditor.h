/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

#include "PluginProcessor.h"

#include <string>
using namespace std;


class MainTab  : public TabbedComponent
{
public:
    
    MainTab (AudioProcessor& p)
    : TabbedComponent (TabbedButtonBar::TabsAtTop)
    {
        //        addTab ("Interface",  Colours::grey, new InterfaceComponent(s, p), true);
        //        addTab ("Data",  Colours::grey, new DataComponent((InterfaceComponent *)getTabContentComponent(0)), true);
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
    

    //PARAMETERS//
    
    Slider wetMixSlider;
    Slider dryMixSlider;
    
    MainTab mt;
   
    
    
    
    //Sliders for delays//
    
    Slider delaysWet[8];

    
    NewProjectAudioProcessor* getProcessor() const
    {
        return static_cast <NewProjectAudioProcessor*> (getAudioProcessor());
    }
   
    

};








