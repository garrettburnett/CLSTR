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


class CLSTRLookAndFeel : public LookAndFeel_V4{
    
public:
    
    CLSTRLookAndFeel();
    virtual ~CLSTRLookAndFeel();
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CLSTRLookAndFeel);
    
    
    
};



#endif /* CLSTRLookAndFeel_h */
