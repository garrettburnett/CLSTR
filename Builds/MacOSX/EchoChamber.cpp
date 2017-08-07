//
//  EchoChamber.cpp
//  Delay Designer
//
//  Created by Garrett on 5/7/17.
//
//

#include <stdio.h>
#include "EchoChamber.h"

EchoChamber::EchoChamber(){
    
}

EchoChamber::~EchoChamber(){
    
    
}

void EchoChamber::setDelayLength(float _bpm, float _sampleRate){
    
    delayLength = (60/_bpm)/4; //default to a 16th note.
    delayLength = delayLength * offset;
    delayInSamples = delayLength *_sampleRate;
}

float* EchoChamber::delayData(int _channel){
    
    float* data = delayBuffer.getWritePointer(jmin(_channel, delayBuffer.getNumChannels()-1));
    
    return data;
}

void EchoChamber::initialize(int _sampleRate){
    
    delayBufferLength = 1;
    delayReadPosition = 0;
    delayWritePosition = 0;
    
    delayBufferLength  = (int) 2.0 * _sampleRate;
    if (delayBufferLength < 1)
        delayBufferLength = 1;
    
    delayBuffer.setSize(2, delayBufferLength);
    delayBuffer.clear();
    
    delayReadPosition = (int) (delayWritePosition - (delayLength * _sampleRate) + delayBufferLength) % delayBufferLength;
    
}
