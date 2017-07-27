//
// CLSTRLookAndFeel.cpp
//  Delay Designer
//
//  Created by Garrett on 7/16/17.
//
//

#include "CLSTRLookAndFeel.h"

CLSTRLookAndFeel::CLSTRLookAndFeel()
{
    setColour (Slider::trackColourId, Colours::white);
    setColour (Slider::textBoxOutlineColourId, Colour::fromRGBA(255,255,255,0));
}


CLSTRLookAndFeel::~CLSTRLookAndFeel()
{
}



void CLSTRLookAndFeel::drawLinearSlider(Graphics& g,
                                       int x, int y,
                                       int w, int h,
                                       float sliderPos,
                                       float minSliderPos,
                                       float maxSliderPos,
                                       const Slider::SliderStyle style,
                                       Slider& slider)
{
    g.setColour (Colour::fromRGBA(255,255,255,125));
    g.drawRoundedRectangle(x, y, w, h, 9, 1);
    g.fillRoundedRectangle(x, h, w, ((h-sliderPos)*-1), 0);
    
}


CLSTRLookAndFeel2::CLSTRLookAndFeel2()
{
    setColour (Slider::trackColourId, Colours::white);
    setColour (Slider::textBoxOutlineColourId, Colour::fromRGBA(255,255,255,0));
}


CLSTRLookAndFeel2::~CLSTRLookAndFeel2()
{
}


void CLSTRLookAndFeel2::drawLinearSlider(Graphics& g,
                                        int x, int y,
                                        int w, int h,
                                        float sliderPos,
                                        float minSliderPos,
                                        float maxSliderPos,
                                        const Slider::SliderStyle style,
                                        Slider& slider)
{
    g.setColour (Colour::fromRGBA(255,255,255,255));
    g.drawRect(x, y, w, h,  1);
    
//    g.fillRect(x, h, w, ((h-sliderPos)*-1));
    g.fillRect(x, h, w, (h-(int)sliderPos)*-1);

    
}

