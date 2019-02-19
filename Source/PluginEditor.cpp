/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionVstAudioProcessorEditor::DistortionVstAudioProcessorEditor (DistortionVstAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

	addAndMakeVisible(driveKnob = new Slider("Drive"));
	driveKnob->setSliderStyle(Slider::RotaryHorizontalDrag); 
	driveKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(rangeKnob = new Slider("Range"));
	rangeKnob->setSliderStyle(Slider::RotaryHorizontalDrag);
	rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(blendKnob = new Slider("Blend"));
	blendKnob->setSliderStyle(Slider::RotaryHorizontalDrag);
	blendKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	addAndMakeVisible(volumeKnob = new Slider("Volume"));
	volumeKnob->setSliderStyle(Slider::RotaryHorizontalDrag);
	volumeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

	driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveKnob);
	rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
	blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendKnob);
	volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volumeKnob);

	setSize(425, 200);
}

DistortionVstAudioProcessorEditor::~DistortionVstAudioProcessorEditor()
{
}

//==============================================================================
void DistortionVstAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

	g.setColour(Colours::ghostwhite);
	g.setFont(18.0f);

	g.drawText("Drive", ((getWidth() / 5) * 1) - 75, (getHeight() / 2) + 5, 100, 100, Justification::centred, false);
	g.drawText("Range", ((getWidth() / 5) * 2) - 75, (getHeight() / 2) + 5, 100, 100, Justification::centred, false);
	g.drawText("Blend", ((getWidth() / 5) * 3) - 75, (getHeight() / 2) + 5, 100, 100, Justification::centred, false);
	g.drawText("Volume", ((getWidth() / 5) * 4) - 75, (getHeight() / 2) + 5, 100, 100, Justification::centred, false);

}

void DistortionVstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	driveKnob->setBounds(((getWidth() / 5) * 1) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
	rangeKnob->setBounds(((getWidth() / 5) * 2) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
	blendKnob->setBounds(((getWidth() / 5) * 3) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
	volumeKnob->setBounds(((getWidth() / 5) * 4) - (100 / 2), (getHeight() / 2) - (100 / 2), 100, 100);
}