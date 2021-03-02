/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "UI/adsrComponent.h"
#include "UI/oscComponent.h"

//==============================================================================
/**
*/
class SupersawDesignerPrototypeAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SupersawDesignerPrototypeAudioProcessorEditor (SupersawDesignerPrototypeAudioProcessor&);
    ~SupersawDesignerPrototypeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SupersawDesignerPrototypeAudioProcessor& audioProcessor;
    OscComponent osc;
    AdsrComponent adsr;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SupersawDesignerPrototypeAudioProcessorEditor)
};
