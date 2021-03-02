/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SupersawDesignerPrototypeAudioProcessorEditor::SupersawDesignerPrototypeAudioProcessorEditor (SupersawDesignerPrototypeAudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p), osc (audioProcessor.apvts, "OSC1WAVETYPE"), adsr (audioProcessor.apvts)
{
    setSize (400, 300);
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
}

SupersawDesignerPrototypeAudioProcessorEditor::~SupersawDesignerPrototypeAudioProcessorEditor()
{
}

//==============================================================================
void SupersawDesignerPrototypeAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
}

void SupersawDesignerPrototypeAudioProcessorEditor::resized()
{
    //set osc selector bounds
    osc.setBounds(10, 10, 100, 30);

    //set adsr bounds
    adsr.setBounds (getWidth() / 2, 0, getWidth() / 2, getHeight());
    
}
