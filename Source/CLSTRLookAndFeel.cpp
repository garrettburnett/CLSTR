//
// CLSTRLookAndFeel.cpp
//  Delay Designer
//
//  Created by Garrett on 7/16/17.
//
//

#include "CLSTRLookAndFeel.h"


enum ColourIds{
    mainBackgroundColourId          = 0x2340000,
};

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
    
    //draw rounded border holder for slider
    g.drawRoundedRectangle(x, y, w, h, 9, 1);
    
    //create a path to cut off the "inner slider", part you interact with. We do this because rounded rectangles get wonky when their height is dynamic. We add an identical rounded rectangle as a clipping path to hide the sharp edges of the inner slider rectangle we are drawing.
    Path inclusionArea;
    inclusionArea.addRoundedRectangle(x, y, w, h, 9);
    
    g.reduceClipRegion(inclusionArea);
    g.fillRect(x, h+1, w, ((int)(h-sliderPos+1)*-1));
    
   
    

    
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
    
    g.fillRect(x, h, w, (h-(int)sliderPos)*-1);
    

    
}

int CLSTRLookAndFeel2::getTabButtonBestWidth(TabBarButton&, int)   { return 110; }


static Colour getTabBackgroundColour(TabBarButton& button){
    const Colour bkg(button.findColour(mainBackgroundColourId).contrasting(0.15f));
    
    if(button.isFrontTab())
        return bkg.overlaidWith(Colours::white);
    
    return Colour::fromRGBA(0, 0, 0, 0);
}

void CLSTRLookAndFeel2::drawTabButton(TabBarButton& button, Graphics& g, bool isMouseOver, bool isMouseDown){
    
    
    Rectangle<int> activeArea(button.getActiveArea());
    activeArea = activeArea.withTrimmedBottom(1);
    
    const Colour bkg(getTabBackgroundColour(button));
    
    g.setGradientFill(ColourGradient(bkg.brighter(0.1f), 0, float(activeArea.getY()),
                                     bkg.darker(0.1f), 0, float(activeArea.getBottom()), false));
    g.fillRect(activeArea);
    g.drawRect(activeArea);
    
    const float alpha = button.isEnabled() ? ((isMouseOver || isMouseDown) ? 1.f : 0.8f) : 0.3f;
    const Colour col(bkg.contrasting().withMultipliedAlpha(alpha));
    
    TextLayout textLayout;
    LookAndFeel_V3::createTabTextLayout(button, float(activeArea.getWidth()), float(activeArea.getHeight()), col, textLayout);
    
    textLayout.draw(g, button.getTextArea().toFloat());
}

