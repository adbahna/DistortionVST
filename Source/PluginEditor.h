/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "MainComponent.h"

//==============================================================================
/**
*/

class CustomSlider : public LookAndFeel_V4 {
public:
	CustomSlider()
	{
		setColour(Slider::thumbColourId, Colours::red);
		setDefaultSansSerifTypefaceName("Roboto");
	}
	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
	{
		auto radius = jmin(width / 2, height / 2) - 8.0f;
		auto centreX = x + width * 0.5f;
		auto centreY = y + height * 0.5f;
		auto rx = centreX - radius;
		auto ry = centreY - radius;
		auto rw = radius * 2.0f;
		auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

		// fill
		g.setColour(Colour((uint8)255, 255, 255, (uint8)64));
		g.fillEllipse(rx - 1, ry - 2, rw + 1, rw);
		g.setColour(Colour((uint8)8, 9, 10, (uint8) 64));
		g.fillEllipse(rx - 2, ry + 4, rw + 4, rw);
		g.setColour(Colour(64, 61, 57));
		g.fillEllipse(rx, ry, rw, rw);
	
		// outline
		g.setColour(Colour(68, 65, 60));
		g.drawEllipse(rx, ry, rw, rw, 2.0f);

		Path p;
		auto pointerLength = radius * 0.66f;
		auto pointerThickness = 3.0f;
		p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
		p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));

		// pointer
		g.setColour(Colour(235, 94, 40));
		g.fillPath(p);
	}

	static const Font & getManropeFont()
	{
		static Typeface::Ptr manrope = Typeface::createSystemTypefaceFor(BinaryData::bold_otf,
																	      BinaryData::bold_otfSize);

		return manrope;
	}
};

//Add extra look and feel class for image knob testing.
//Load from cache 
//Learn about file structure for Juce

class DistortionVstAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    DistortionVstAudioProcessorEditor (DistortionVstAudioProcessor&);
    ~DistortionVstAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:

	CustomSlider customSlider;

	ScopedPointer<Slider> driveKnob;
	ScopedPointer<Slider> rangeKnob;
	ScopedPointer<Slider> blendKnob; 
	ScopedPointer<Slider> volumeKnob; 
	
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> driveAttachment; 
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> rangeAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendAttachment;
	ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> volumeAttachment;

    DistortionVstAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionVstAudioProcessorEditor)
};
