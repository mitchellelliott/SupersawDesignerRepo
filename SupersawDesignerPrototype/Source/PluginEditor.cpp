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
    setSize (700, 600);
    addAndMakeVisible(osc1);
    addAndMakeVisible(osc2);
    addAndMakeVisible(adsr);
    
    
    //Gain Slider 1
    gainSlider1.addListener(this);
    gainSlider1.setBounds(sliderStartX,sliderStartY,sliderWidth,sliderHeight);
    gainSlider1.setSliderStyle(juce::Slider::LinearVertical);
    gainSlider1.setValue(audioProcessor.osc1Gain);
    gainSlider1.setRange(0.f,1.f,0.01f);
    gainSlider1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 35, 25);
    addAndMakeVisible(gainSlider1);
    
    //unison Slider 1
    unisonSlider1.addListener(this);
    unisonSlider1.setBounds(gainSlider1.getRight()+padding,sliderStartY,sliderWidth,sliderHeight);
    unisonSlider1.setSliderStyle(juce::Slider::LinearVertical);
    unisonSlider1.setValue(audioProcessor.osc1Unison);
    unisonSlider1.setRange(1.f,7.f,1.f);
    unisonSlider1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 25, 25);
    addAndMakeVisible(unisonSlider1);
    
    //Spread Slider 1
    spreadSlider1.addListener(this);
    spreadSlider1.setBounds(unisonSlider1.getRight()+padding,sliderStartY,sliderWidth,sliderHeight);
    spreadSlider1.setSliderStyle(juce::Slider::LinearVertical);
    spreadSlider1.setValue(audioProcessor.osc1Spread);
    spreadSlider1.setRange(1.f,14.f,1.f);
    spreadSlider1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 25, 25);
    addAndMakeVisible(spreadSlider1);
    
    //Tune Slider 1
    tuneSlider1.addListener(this);
    tuneSlider1.setBounds(spreadSlider1.getRight()+padding,sliderStartY,sliderWidth,sliderHeight);
    tuneSlider1.setSliderStyle(juce::Slider::LinearVertical);
    tuneSlider1.setValue(audioProcessor.osc1Tune);
    tuneSlider1.setRange(-50.f,50.f,1.f);
    tuneSlider1.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 35, 25);
    addAndMakeVisible(tuneSlider1);
    
}

SupersawDesignerPrototypeAudioProcessorEditor::~SupersawDesignerPrototypeAudioProcessorEditor()
{
}

//==============================================================================
void SupersawDesignerPrototypeAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);
    
    g.setColour(juce::Colours::gold);
    g.setFont (juce::Font ("Helvetica Neue", 32.f, juce::Font::bold));
    g.drawFittedText("Supersaw Designer",getLocalBounds(), juce::Justification::centredTop, 1);
    
    //Osc1 Level Label
    g.setColour(juce::Colours::gold);
    g.setFont(juce::Font ("Helvetica Neue", 15.f, juce::Font::underlined));
    g.drawFittedText("Level", sliderStartX+25 , sliderStartY-20, 50, 50, juce::Justification::centredTop, 1);

    //Osc1 Unison Label
    g.setColour(juce::Colours::gold);
    g.setFont(juce::Font ("Helvetica Neue", 15.f, juce::Font::underlined));
    g.drawFittedText("Unison", gainSlider1.getRight()+padding+25 , sliderStartY-20, 50, 50, juce::Justification::centredTop, 1);
   
    //Osc1 Spread Label
    g.setColour(juce::Colours::gold);
    g.setFont(juce::Font ("Helvetica Neue", 15.f, juce::Font::underlined));
    g.drawFittedText("Spread", unisonSlider1.getRight()+padding+25 , sliderStartY-20, 50, 50, juce::Justification::centredTop, 1);
    
    //Osc1 Tune Label
    g.setColour(juce::Colours::gold);
    g.setFont(juce::Font ("Helvetica Neue", 15.f, juce::Font::underlined));
    g.drawFittedText("Tune", spreadSlider1.getRight()+padding+25 , sliderStartY-20, 50, 50, juce::Justification::centredTop, 1);
    
    
}

void SupersawDesignerPrototypeAudioProcessorEditor::resized()
{
    //set osc selector bounds
    osc1.setBounds(25, 75, 100, 50);
    osc2.setBounds(25, 250, 100, 50);

    //set adsr bounds
    adsr.setBounds(0, 400, getWidth()/3, getHeight()/3);
    
}

void SupersawDesignerPrototypeAudioProcessorEditor::sliderValueChanged(juce::Slider *slider){
    
    if (slider == &gainSlider1){
        audioProcessor.osc1Gain = gainSlider1.getValue();
    }
    if (slider == &unisonSlider1){
        audioProcessor.osc1Unison = unisonSlider1.getValue();
    }
    if (slider == &spreadSlider1){
        audioProcessor.osc1Spread = spreadSlider1.getValue();
    }
    if (slider == &tuneSlider1){
        audioProcessor.osc1Tune = tuneSlider1.getValue();
    }
    
}
