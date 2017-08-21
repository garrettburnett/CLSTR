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
    LookAndFeel::setDefaultLookAndFeel(&laf);
    LookAndFeel::getDefaultLookAndFeel().setDefaultSansSerifTypefaceName ("Montserrat");
    
    
    startTimer(30);
    //TAB
    addAndMakeVisible(mt);
    
    mt.getTabbedButtonBar();
    
    
    mt.setOutline(0);
    mt.addTab("VOLUME", Colour::Colour(),new Component(),true);
    mt.addTab("PAN", Colour::Colour(),new Component(),true);
    mt.addTab("PITCH", Colour::Colour(),new Component(),true);
    mt.addTab("FILTER", Colour::Colour(),new Component(),true);
    mt.addTab("BIT CRUNCH", Colour::Colour(),new Component(),true);
    mt.getTabbedButtonBar().setLookAndFeel(&laf2);
    
    
    mt.getTabbedButtonBar().getTabButton(0)->setLookAndFeel(&laf2);
    mt.getTabbedButtonBar().getTabButton(1)->setLookAndFeel(&laf2);
    mt.getTabbedButtonBar().getTabButton(2)->setLookAndFeel(&laf2);
    mt.getTabbedButtonBar().getTabButton(3)->setLookAndFeel(&laf2);
    mt.getTabbedButtonBar().getTabButton(4)->setLookAndFeel(&laf2);
    
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
        delayS[i].setPopupDisplayEnabled (false, this);
        delayS[i].setTextValueSuffix (" Delay Wet");
        delayS[i].setValue(p.delayParameters[i]->get());
        mt.getTabContentComponent(0)->addAndMakeVisible(&delayS[i]);
        delayS[i].addListener(this);
        delayS[i].setLookAndFeel (&laf2);
        panS[i].setSliderStyle (Slider::LinearBarVertical);
        panS[i].setRange (0.0, 1.0, 0.01);
        panS[i].setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        panS[i].setPopupDisplayEnabled (false   , this);
        panS[i].setTextValueSuffix (" Pan");
        panS[i].setValue(p.panParameters[i]->get());
        mt.getTabContentComponent(1)->addAndMakeVisible(&panS[i]);
        panS[i].addListener(this);
        panS[i].setLookAndFeel (&laf2);
        
        //FILTERS
        
        filterS[i].setSliderStyle (Slider::LinearBarVertical);
        filterS[i].setRange (0.0, 1.0, 0.01);
        filterS[i].setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
        filterS[i].setPopupDisplayEnabled (false, this);
        filterS[i].setTextValueSuffix (" Hz");
        mt.getTabContentComponent(3)->addAndMakeVisible(&filterS[i]);
        filterS[i].addListener(this);
        filterS[i].setLookAndFeel (&laf2);
    }
    
    
    mt.getTabbedButtonBar().getTabButton(0)->addListener(this);
    mt.getTabbedButtonBar().getTabButton(1)->addListener(this);
    mt.getTabbedButtonBar().getTabButton(2)->addListener(this);
    mt.getTabbedButtonBar().getTabButton(3)->addListener(this);
    mt.getTabbedButtonBar().getTabButton(4)->addListener(this);

}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}



void NewProjectAudioProcessorEditor::timerCallback(){ //update UI from parameter changes
   
    wetMixSlider.setValue(processor.wetMixParameter->get(), dontSendNotification);
    dryMixSlider.setValue(processor.dryMixParameter->get(), dontSendNotification);

    for(int i = 0; i<8; i++){
        delayS[i].setValue(processor.delayParameters[i]->get(), dontSendNotification);
        panS[i].setValue(processor.panParameters[i]->get(), dontSendNotification);
        filterS[i].setValue(processor.filterParameters[i]->get(), dontSendNotification);
        
    }
}

void NewProjectAudioProcessorEditor::sliderValueChanged (Slider *slider)

{
    if (slider == &wetMixSlider){//index 0,
        processor.wetMixParameter->setValueNotifyingHost((float) wetMixSlider.getValue());
    }
    else if (slider == &dryMixSlider){//index 1,
        processor.dryMixParameter->setValueNotifyingHost((float) dryMixSlider.getValue());
    }
    
    for( int i = 0; i<8; i++){
        if (slider == &delayS[i]){
            processor.delayParameters[i]->setValueNotifyingHost((float) delayS[i].getValue());
        }
        
        if (slider == &panS[i]){
            processor.panParameters[i]->setValueNotifyingHost((float) panS[i].getValue());
        }
        if (slider == &filterS[i]){
            processor.filterParameters[i]->setValueNotifyingHost((float) filterS[i].getValue());
        }
    }
  
}

void NewProjectAudioProcessorEditor::buttonClicked (Button* button)
{//this function changes the component background color on new tab.
    
    if(button == mt.getTabbedButtonBar().getTabButton(0)){
        active1 = vol1;
        active2 = vol2;
    }
    else if(button == mt.getTabbedButtonBar().getTabButton(1)){
        active1 = pan1;
        active2 = pan2;
    }
    else if(button == mt.getTabbedButtonBar().getTabButton(2)){
        active1 = pitch1;
        active2 = pitch2;
    }
 
    else if(button == mt.getTabbedButtonBar().getTabButton(3)){
        active1 = filter1;
        active2 = filter2;
    }
    else if(button == mt.getTabbedButtonBar().getTabButton(4)){
        active1 = bit1;
        active2 = bit2;
    }
    
    repaint(); //repaint entire component
}


//==============================================================================
void NewProjectAudioProcessorEditor::paint (Graphics& g)
{
 
    g.setGradientFill(ColourGradient(
                        active1,0,0,
                        active2,(float)getWidth(),(float) getHeight(), false));
    g.fillAll();
    g.setColour (Colours::white);
    
    Font mainFont("Montserrat", 30.0f, Font::plain);
    Font secondaryFont("Montserrat", 10.0f, Font::plain);
    Font titleFont("Montserrat Light", 35.0f, Font::plain);
    
//    mainFont.setExtraKerningFactor(.2);
      secondaryFont.setExtraKerningFactor(.2);
    g.setFont (titleFont);
    g.drawText("CLSTR", 35, 40, 200,20, Justification::centredLeft, true);
    g.setFont(secondaryFont);
    g.drawText("CLSTR by G Burnett, 2017", getWidth()-190, getHeight() - 30, 200,20, Justification::centredLeft, true);
  
    g.drawText("WET", getWidth()-70, getHeight() - 90, 40,20, Justification::centredTop, true);
    g.drawText("DRY", 35, getHeight() - 90, 40,20, Justification::centredTop, true);
    
    g.setColour (Colours::white);
    g.drawLine(125, 371, 673, 371,3 );

    for(int i = 0; i< 9; i++){
        int offset = i * 30;
        
        g.setColour(Colour::fromRGBA(255, 255, 255, 50));
        g.drawLine(125, 341 - offset, 675, 341 - offset);
        
    }
    
    
}

void NewProjectAudioProcessorEditor::resized()
{
    wetMixSlider.setBounds (getWidth()-62, 100, 20, 250);
    dryMixSlider.setBounds (43, 100, 20, 250);
    
    mt.setBounds(125,100,550, getHeight()-150);
    
  
    
    for(int i = 0; i< 8; i++){
        delayS[i].setBounds ((77*(i)), -1, 11, mt.getHeight()-30);
        panS[i].setBounds ((77*(i)), -1, 11, mt.getHeight()-30);
         filterS[i].setBounds ((77*(i)), -1, 11, mt.getHeight()-30);
    }
    
}






