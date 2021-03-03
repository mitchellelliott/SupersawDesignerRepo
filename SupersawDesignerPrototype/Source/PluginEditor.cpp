/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SupersawDesignerPrototypeAudioProcessorEditor::SupersawDesignerPrototypeAudioProcessorEditor (SupersawDesignerPrototypeAudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p), osc1 (audioProcessor.apvts, "OSC1WAVETYPE"), osc2 (audioProcessor.apvts, "OSC2WAVETYPE"), adsr (audioProcessor.apvts)
{
    setSize (1000, 600);
    addAndMakeVisible(osc1);
    addAndMakeVisible(osc2);
    addAndMakeVisible(adsr);
    
    gainSlider1.addListener(this);
    gainSlider1.setBounds(150,60,100,100);
    gainSlider1.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider1.setValue(audioProcessor.osc1Gain);
    gainSlider1.setRange(0.f,1.f,0.01f);
    gainSlider1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 25, 25);
    addAndMakeVisible(gainSlider1);
    
}

SupersawDesignerPrototypeAudioProcessorEditor::~SupersawDesignerPrototypeAudioProcessorEditor()
{
}

//==============================================================================
void SupersawDesignerPrototypeAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    
    g.setColour(juce::Colours::goldenrod);
    g.setFont (juce::Font ("Helvetica Neue", 40.f, juce::Font::italic));
    g.drawFittedText("Supersaw Designer",getLocalBounds(), juce::Justification::centredTop, 1);
    
    g.setColour(juce::Colours::gold);
    g.setFont(juce::Font ("Helvetica Neue", 20.f, juce::Font::underlined));
    g.drawFittedText("Level", 175, 40, 50, 50, juce::Justification::centredTop, 1);
}

void SupersawDesignerPrototypeAudioProcessorEditor::resized()
{
    //set osc selector bounds
    osc1.setBounds(25, 75, 100, 50);
    osc2.setBounds(25, 250, 100, 50);

    //set adsr bounds
    adsr.setBounds(0, 400, getWidth()/4, getHeight()/3);
    
}

void SupersawDesignerPrototypeAudioProcessorEditor::sliderValueChanged(juce::Slider *slider){
    
    if (slider == &gainSlider1){
        audioProcessor.osc1Gain = gainSlider1.getValue();
    }
}
