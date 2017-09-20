//
//  CustomLookAndFeel.h
//  Delay Designer
//
//  Created by Garrett on 7/16/17.
//
//

#ifndef CLSTRLookAndFeel_h
#define CLSTRLookAndFeel_h

#include <stdio.h>
#include "../JuceLibraryCode/JuceHeader.h"


class CLSTRLookAndFeel : public LookAndFeel_V4
{
    
public:
    
    CLSTRLookAndFeel();
    virtual ~CLSTRLookAndFeel();
    virtual void drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos,
                                  const Slider::SliderStyle style, Slider& slider);
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CLSTRLookAndFeel);
};

class CLSTRLookAndFeel2 : public LookAndFeel_V4{
public:
    
    CLSTRLookAndFeel2();
    virtual ~CLSTRLookAndFeel2();
    
    virtual void drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos,
                                  const Slider::SliderStyle style, Slider& slider);
    
    void drawTabButton(TabBarButton& button, Graphics& g, bool isMouseOver, bool isMouseDown) override;
        int getTabButtonBestWidth(TabBarButton&, int tabDepth) override;
    
    void drawTabButtonText(Graphics& g,
                           int x, int y, int w, int h,
                           const Colour& preferredBackgroundColour,
                           int /*tabIndex*/,
                           const String& text,
                           Button& button,
                           TabbedButtonBar::Orientation orientation,
                           const bool isMouseOver,
                           const bool isMouseDown,
                           const bool isFrontTab);
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CLSTRLookAndFeel2);
};


#endif /* CLSTRLookAndFeel_h */
