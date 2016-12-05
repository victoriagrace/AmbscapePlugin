/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#ifndef max
#define max(A, B) ((A > B) ? A : B)
#endif

#ifndef min
#define min(A, B) ((A < B) ? A : B)
#endif

static const int notes_1[] = {9, 11};
static const int notes_2[] = {3, 5};
static const int minor_scale[] = {0, 2, 3, 5, 7, 8, 11};
static const int major_scale[] = {0, 2, 4, 5, 7, 9, 11};

static const int sopranoTable[] = {59, 60, 61, 61, 61, 59};
static const int altoTable[] = {56, 56, 56, 57, 57, 54};
static const int tenorTable[] = {40, 39, 40, 40, 37, 39};
static const int bassTable[] = {35, 24, 25, 33, 42, 33};

static const int scaleTable[][4] = {
    {35, 40, 56, 59},
    {24, 39, 56, 60},
    {25, 40, 56, 61},
    {33, 40, 57, 61},
    {42, 37, 57, 61},
    {33, 39, 54, 59},
};


//static const int chord[] =
//==============================================================================
AmbscapePluginAudioProcessorEditor::AmbscapePluginAudioProcessorEditor (AmbscapePluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1000, 1000);
    
    for(int i = 0; i < NUMFRAMES; i++) {
        //File image = (String)"/Users/victoriagrace/Desktop/Music 256A/ambscapePlugin/greenball.png";
        File image = (String)"/Users/victoriagrace/Desktop/Music 256A/ambscapePlugin/Source/res/ball_pull_" + std::to_string(i) + ".png";
        
        
        String filePath =        (String)"/Users/victoriagrace/Desktop/Music 256A/ambscapePlugin/Source/res/" + "ball_" + std::to_string(i) + ".png";

        File imagePress = filePath;
        
        juceImage[i] = ImageFileFormat::loadFrom(image);
        juceImagePress[i] = ImageFileFormat::loadFrom(imagePress);
    }

    processor.setParam("/fm/gate",0.0);

}

AmbscapePluginAudioProcessorEditor::~AmbscapePluginAudioProcessorEditor()
{
    
}

//==============================================================================
void AmbscapePluginAudioProcessorEditor::paint (Graphics& g)
{
    int index = (int)floor(pull * NUMFRAMES);
    index = (NUMFRAMES - 1) - index;
    index = min(max(index, 0), NUMFRAMES - 1);
    g.fillAll (Colours::black);

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawImageAt(juceImage[index],
                  xPos - (juceImage[index].getWidth() * 0.5),
                  yPos - (juceImage[index].getHeight() * 0.5),
                  false);
    
    
    g.drawImageAt(juceImagePress[index],
                  xPos2 - (juceImagePress[index].getWidth() * 0.5),
                  yPos2 - (juceImagePress[index].getHeight() * 0.5),
                  false);
    
//    std::cout << pull << "\n";

    //std::cout << "Width: " << juceIzmage.getWidth() << " Height: " << juceImage.getHeight() << "\n";
    
//    g.drawEllipse(xPos , yPos, 10.0, 10.0, 2.0);

//    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
    // find recall/ redraw paint
}
//void AmbscapePluginAudioProcessorEditor::repaint (Graphics& g)
//{
////    g.fillAll (Colours::black);
////    
////    g.setColour (Colours::white);
////    g.setFont (15.0f);
//    
//    g.drawEllipse(xPos , yPos, 10.0, 10.0, 2.0);
//    
//    //    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
//    // find recall/ redraw paint
//}


void AmbscapePluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void AmbscapePluginAudioProcessorEditor::mouseDown(const MouseEvent &evt)
{
    processor.setParam("/fm/gate", 1);
}

void AmbscapePluginAudioProcessorEditor::mouseUp(const MouseEvent &evt)
{
    processor.setParam("/fm/gate", 0);

}
void AmbscapePluginAudioProcessorEditor::mouseDrag(const MouseEvent &evt)
{
    Rectangle<int> area = getScreenBounds();
    float x =(float) evt.getDistanceFromDragStartX() / area.getWidth();
    float y =(float) evt.getDistanceFromDragStartY() / area.getHeight();
    
    float x2=(float) x-0.5;
    
    float pressedX =(float) evt.getMouseDownX() / area.getWidth();
    float pressedY =(float) evt.getMouseDownY() / area.getHeight();
    float offset = (float)10;
    
    /* clamp our values */
    pull = min(max(sqrtf(x*x + y*y), 0.0f), 1.0f);
    float rot;
    if (x == 0) {
        rot = 0;
    } else {
        rot = atan(y/x)/ (M_PI / 2.0);
        rot= (rot+1.0)*0.5;
    }
    
    //std::cout << "x: " << x << "\n";
    
//    int xposition= getMouseDownScreenX();
    
    float xFreq = (x +7.0) *10.0;
    float index = (x+1.8)/3.4;
    
    int ambNote =  pressedX;
    float leadNote = ambNote+(x2*200);
    // TODO: implement length of mouse
    //int 	getLengthOfMousePress ()
   
    processor.setParam("/fm/pull",pull);
    processor.setParam("/fm/rotation",rot);
    //std::cout << "rotation: " << rot << "\n";
    
  //  processor.setParam("/fm/freq",ambNote);
 //  processor.setParam("/fm/lead",leadNote);
   // processor.setParam("/fm/indx",index);
   // processor.setParam("/fm/mod",index);
    
    
    xPos = evt.getMouseDownX() + evt.getDistanceFromDragStartX();
    yPos = evt.getMouseDownY() + evt.getDistanceFromDragStartY();
    
    //evt.getMouseDownX();
    //evt.getMouseDownY();

    xPos2 = evt.getMouseDownX();
    yPos2 = evt.getMouseDownY();
    
    yPosChord = minor_scale[(int)floor(((float)evt.getMouseDownY() / area.getHeight()) * 7)];
    yPosLead = notes_2[(int)floor(((float)evt.getMouseDownX() / area.getWidth()) * 2)];

//    processor.setParam("/fm/note_1", yPosChord);
//    processor.setParam("/fm/note_2", yPosLead);
//    
    
    int chordNumber =(int)floor(((float)evt.getMouseDownX()/area.getWidth())*6);
    int scaleNumber = (int)floor(rot * 4);
    processor.setParam("/fm/lead", scaleTable[chordNumber][scaleNumber]+12);
    
    soprano= sopranoTable[chordNumber];
    alto= altoTable[chordNumber];
    tenor= tenorTable[chordNumber];
    bass= bassTable[chordNumber];
    
    
    processor.setParam("/fm/soprano", soprano );
    processor.setParam("/fm/alto", alto );
    processor.setParam("/fm/tenor", tenor );
    processor.setParam("/fm/bass", bass );
    
    //std::cout << soprano << "\n";
    
    
    repaint();

//    g.drawEllipse(100, 100, 10.0, 10.0, 2.0);
//
//    g.setColour (Colours::white);



}
