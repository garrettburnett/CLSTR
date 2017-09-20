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
class NewProjectAudioProcessorEditor  : public AudioProcessorEditor,
private Slider::Listener,
public Timer,
public ButtonListener
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void timerCallback(); //to update UI sliders
    void buttonClicked (Button* button) override; //add listener

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
    
    Slider delayS[8];
    Slider panS[8];
    Slider filterS[8];

    NewProjectAudioProcessor* getProcessor() const
    {
        return static_cast <NewProjectAudioProcessor*> (getAudioProcessor());
    }
    
    //Color sets
    Colour vol1 = Colour::fromRGB(73, 135, 207);
    Colour vol2 = Colour::fromRGB(0, 68, 147);
    
    Colour pan1 = Colour::fromRGB(255, 172, 183);
    Colour pan2 = Colour::fromRGB(215, 63, 83);
    
    Colour pitch1 = Colour::fromRGB(144, 226, 204);
    Colour pitch2 = Colour::fromRGB(31, 142, 159);
    
    Colour filter1 = Colour::fromRGB(196, 57, 184);
    Colour filter2 = Colour::fromRGB(243, 74, 96);
    
    Colour bit1 = Colour::fromRGB(18, 39, 54);
    Colour bit2 = Colour::fromRGB(71, 71, 102);
    
    Colour active1 = vol1;
    Colour active2 = vol1;

};
