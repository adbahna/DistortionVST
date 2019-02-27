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

	LookAndFeel_V4::setDefaultLookAndFeel(&customSlider);

	addAndMakeVisible(driveKnob = new Slider("Drive"));
	driveKnob->setSliderStyle(Slider::RotaryVerticalDrag);
	driveKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	driveKnob->setMouseDragSensitivity(150);

	addAndMakeVisible(rangeKnob = new Slider("Drive"));
	rangeKnob->setSliderStyle(Slider::RotaryVerticalDrag);
	rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	rangeKnob->setMouseDragSensitivity(150);

	 
	addAndMakeVisible(blendKnob = new Slider("Blend"));
	blendKnob->setSliderStyle(Slider::RotaryVerticalDrag);
	blendKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	blendKnob->setMouseDragSensitivity(150);


	addAndMakeVisible(volumeKnob = new Slider("Volume"));
	volumeKnob->setSliderStyle(Slider::RotaryVerticalDrag);
	volumeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
	volumeKnob->setMouseDragSensitivity(150);

	driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "drive", *driveKnob);
	rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "range", *rangeKnob);
	blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "blend", *blendKnob);
	volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "volume", *volumeKnob);

	setSize(400,  150);
}

DistortionVstAudioProcessorEditor::~DistortionVstAudioProcessorEditor()
{
}

//==============================================================================
void DistortionVstAudioProcessorEditor::paint(Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)

	LookAndFeel_V4::setDefaultLookAndFeel(&customSlider);

	g.setFont(18.0f);

	g.setColour(Colour(37, 36, 34));
	g.fillRect(0, 0, 400, 150);

	g.setColour(Colour((uint8)0, 0, 0, (uint8)90));

	g.setColour(Colour((uint8)255, 255, 255, (uint8)10));
	g.fillRect(((getWidth() / 5) * 1) - 57, (getHeight() / 2) + 35, 70, 30);
	g.fillRect(((getWidth() / 5) * 2) - 40, (getHeight() / 2) + 35, 70, 30);
	g.fillRect(((getWidth() / 5) * 3) - 26, (getHeight() / 2) + 35, 70, 30);
	g.fillRect(((getWidth() / 5) * 4) - 11, (getHeight() / 2) + 35, 70, 30);

	g.setColour(Colour((uint8)0, 0, 0, (uint8)10));
	g.fillRect(((getWidth() / 5) * 1) - 55, (getHeight() / 2) + 36, 70, 30);
	g.fillRect(((getWidth() / 5) * 2) - 38, (getHeight() / 2) + 36, 70, 30);
	g.fillRect(((getWidth() / 5) * 3) - 24, (getHeight() / 2) + 36, 70, 30);
	g.fillRect(((getWidth() / 5) * 4) - 9, (getHeight() / 2) + 36, 70, 30);


	g.setColour(Colour((uint8)0, 0, 0, (uint8)90));

	g.drawText("Drive", ((getWidth() / 5) * 1) - 70, (getHeight() / 2) + 2, 100, 100, Justification::centred, false);
	g.drawText("Range", ((getWidth() / 5) * 2) - 53, (getHeight() / 2) + 2, 100, 100, Justification::centred, false);
	g.drawText("Blend", ((getWidth() / 5) * 3) - 39, (getHeight() / 2) + 2, 100, 100, Justification::centred, false);
	g.drawText("Volume", ((getWidth() / 5) * 4) - 24, (getHeight() / 2) + 2, 100, 100, Justification::centred, false);

	g.setColour(Colour(200, 197, 187));

	g.drawText("Drive", ((getWidth() / 5) * 1) - 72, (getHeight() / 2), 100, 100, Justification::centred, false);
	g.drawText("Range", ((getWidth() / 5) * 2) - 55, (getHeight() / 2), 100, 100, Justification::centred, false);
	g.drawText("Blend", ((getWidth() / 5) * 3) - 41, (getHeight() / 2), 100, 100, Justification::centred, false);
	g.drawText("Volume", ((getWidth() / 5) * 4) - 26, (getHeight() / 2), 100, 100, Justification::centred, false);

	g.setColour(Colour((uint8) 255, 255, 255, (uint8)10));

	g.drawText("Drive", ((getWidth() / 5) * 1) - 74, (getHeight() / 2) - 1, 100, 100, Justification::centred, false);
	g.drawText("Range", ((getWidth() / 5) * 2) - 57, (getHeight() / 2) - 1, 100, 100, Justification::centred, false);
	g.drawText("Blend", ((getWidth() / 5) * 3) - 43, (getHeight() / 2) - 1, 100, 100, Justification::centred, false);
	g.drawText("Volume", ((getWidth() / 5) * 4) - 28, (getHeight() / 2) - 1, 100, 100, Justification::centred, false);

}

void DistortionVstAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	driveKnob->setBounds(((getWidth() / 5) * 1) - 72, (getHeight() / 2) - 65, 100, 100);
	rangeKnob->setBounds(((getWidth() / 5) * 2) - 57, (getHeight() / 2) - 65, 100, 100);
	blendKnob->setBounds(((getWidth() / 5) * 3) - 42, (getHeight() / 2) - 65, 100, 100);
	volumeKnob->setBounds(((getWidth() / 5) * 4) - 27, (getHeight() / 2) - 65, 100, 100);
}
