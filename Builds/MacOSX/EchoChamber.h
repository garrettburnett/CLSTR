//
//  EchoChamber.h
//  Delay Designer
//
//  Created by Garrett on 5/7/17.
//
//

#ifndef EchoChamber_h
#define EchoChamber_h

#include "../JuceLibraryCode/JuceHeader.h"

class EchoChamber
{
public:
    EchoChamber();
    ~EchoChamber();
    float delayLength;
    float delayInSamples;
    
    float feedback = 0; //No feedback in this plugin
    
    void setDelayLength(float _bpm, float _sampleRate);
    
    void initialize(int _sampleRate);
    AudioSampleBuffer delayBuffer;
    
    int delayBufferLength;
    int delayReadPosition;
    int delayWritePosition;
    int dpr, dpw;
    int measureOffset;
    int offset =1 ; // this offsets the default 16th note value;
    
    float* delayData(int _channel);
    
private:
    
};


#endif /* EchoChamber_h */
