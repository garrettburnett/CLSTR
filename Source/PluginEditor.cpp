/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p), mt(p)
{
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (800, 450);
//    LookAndFeel::setDefaultLookAndFeel(&laf);
    
    //TAB
    addAndMakeVisible(mt);
    
    mt.getTabbedButtonBar();
    
    mt.setOutline(0);
    mt.addTab("VOLUME", Colour::Colour(),new Component(),true);
    mt.addTab("PAN", Colour::Colour(),new Component(),true);
    mt.addTab("PITCH", Colour::Colour(),new Component(),true);
    mt.addTab("FILTER", Colour::Colour(),new Component(),true);
    mt.addTab("BIT CRUNCH", Colour::Colour(),new Component(),true);
    
    
    wetMixSlider.setSliderStyle (Slider::LinearBarVertical);
    wetMixSlider.setRange(0.0, 1.0, 0.01);
    wetMixSlider.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    wetMixSlider.setPopupDisplayEnabled (false, this);
    wetMixSlider.setTextValueSuffix (" Global Wet");
    wetMixSlider.setValue(p.wetMixParameter->get());
    wetMixSlider.setLookAndFeel(&laf);


    dryMixSlider.setSliderStyle (Slider::LinearBarVertical);
    dryMixSlider.setRange(0.0, 1.0, 0.01);
    dryMixSlider.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    dryMixSlider.setPopupDisplayEnabled (false, this);
    dryMixSlider.setTextValueSuffix (" Dry");
    dryMixSlider.setValue(p.dryMixParameter->get());
    dryMixSlider.setLookAndFeel(&laf);
    
    addAndMakeVisible (&wetMixSlider);
    wetMixSlider.addListener(this);
    
    addAndMakeVisible (&dryMixSlider);
    dryMixSlider.addListener(this);
    
    for(int i = 0; i< 8; i++){ //for each echo chamber
        delayS[i].setSliderStyle (Slider::LinearBarVertical);
        delayS[i].setRange(0.0, 1.0, 0.01);
        delayS[i].setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        delayS[i].setPopupDisplayEnabled (true, this);
        delayS[i].setTextValueSuffix (" Delay Wet");
        delayS[i].setValue(p.delayParameters[i]->get());

        mt.getTabContentComponent(0)->addAndMakeVisible(&delayS[i]);
        delayS[i].addListener(this);
        delayS[i].setLookAndFeel (&laf2);
        
        panS[i].setSliderStyle (Slider::LinearBarVertical);
        panS[i].setRange (-1.0f, 1.0f, 0.01);
        panS[i].setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        panS[i].setPopupDisplayEnabled (true, this);
        panS[i].setTextValueSuffix (" Pan");
        panS[i].setValue(p.panParameters[i]->get());
        //        addAndMakeVisible (&delaysWet[i]);
        mt.getTabContentComponent(1)->addAndMakeVisible(&panS[i]);
        panS[i].addListener(this);
        panS[i].setLookAndFeel (&laf2);
    }
    
    startTimer(50);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

void NewProjectAudioProcessorEditor::timerCallback(){ //update UI from parameter changes
    
    NewProjectAudioProcessor* theProcessor = getProcessor();
    
    wetMixSlider.setValue(theProcessor->wetMixParameter->get(), dontSendNotification);
    dryMixSlider.setValue(theProcessor->dryMixParameter->get(), dontSendNotification);
    
    for(int i = 0; i< 8; i++){
        delayS[i].setValue(theProcessor->delayParameters[i]->get(), dontSendNotification);
        panS[i].setValue(theProcessor->panParameters[i]->get(), dontSendNotification);
    }
    
}

void NewProjectAudioProcessorEditor::sliderValueChanged (Slider* slider)

{
    if (slider == &wetMixSlider){//index 0,
        getProcessor()->setParameterNotifyingHost(0, (float) wetMixSlider.getValue());
    }
    
    if (slider == &dryMixSlider){//index 1,
        getProcessor()->setParameterNotifyingHost(1, (float) dryMixSlider.getValue());
    }
    
    for(int i = 0; i<8; i++){ //delay sliders
        if (slider == &delayS[i]){//indexes 2-9,
            //we say i+2, because 0 and 1 are taken up by wet and dry global
            getProcessor()->setParameterNotifyingHost(i+2, (float) delayS[i].getValue());
        }
        if (slider == &panS[i]){//indexes 2-9,
            getProcessor()->setParameterNotifyingHost(i+10, (float) panS[i].getValue());
        }
    }
}
    

//==============================================================================
void NewProjectAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (Colour::fromRGB(148 ,176, 209));
//    g.setGradientFill(ColourGradient(Colour::fromRGB(73, 135, 207),0,Colour::fromRGB(73, 135, 207), false));
    
    g.setGradientFill(ColourGradient(
                        Colour::fromRGB(73, 135, 207),0,0,
                        Colour::fromRGB(0, 68, 147),(float)getWidth(),(float) getHeight(), false));
    g.fillAll();
    g.setColour (Colours::white);
    
    Font mainFont("Montserrat", 30.0f, Font::plain);
    Font secondaryFont("Montserrat", 12.0f, Font::plain);
    
    mainFont.setExtraKerningFactor(.2);
    secondaryFont.setExtraKerningFactor(.2);

    g.setFont (mainFont);
    
    g.setFont(secondaryFont);
//    g.drawText("WET", getWidth()-77, getHeight() - 90, 40,20, Justification::centredTop, true);
//    g.drawText("DRY", 50, getHeight() - 90, 40,20, Justification::centredTop, true);
    
    g.setColour (Colours::white);
}

void NewProjectAudioProcessorEditor::resized()
{
    wetMixSlider.setBounds (getWidth()-62, 100, 20, 250);
    dryMixSlider.setBounds (43, 100, 20, 250);
    
    mt.setBounds(125,100,550, getHeight()-150);
    
    for(int i = 0; i< 8; i++){
        delayS[i].setBounds ((77*(i)), 0, 11, mt.getHeight()-30);
        panS[i].setBounds ((77*(i)), 0, 11, mt.getHeight()-30);
    }
    
}


