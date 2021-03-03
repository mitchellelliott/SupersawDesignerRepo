/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "synthVoice.h"
#include "UI/adsrComponent.h"
#include "UI/oscComponent.h"

//==============================================================================
/**
*/
class SupersawDesignerPrototypeAudioProcessorEditor  : public juce::AudioProcessorEditor,
public juce::Slider::Listener
{
public:
    SupersawDesignerPrototypeAudioProcessorEditor (SupersawDesignerPrototypeAudioProcessor&);
    ~SupersawDesignerPrototypeAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(juce::Slider * slider) override;

private:
    SupersawDesignerPrototypeAudioProcessor& audioProcessor;
    OscComponent osc1;
    OscComponent osc2;
    AdsrComponent adsr;
    
    juce::Slider gainSlider1;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SupersawDesignerPrototypeAudioProcessorEditor)
};
