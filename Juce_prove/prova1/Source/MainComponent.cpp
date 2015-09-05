/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    addAndMakeVisible (quitButton = new TextButton (String::empty));
    quitButton->setButtonText ("Quit");
    //quitButton->addListener (this);
    
    
    addAndMakeVisible (textButton = new TextButton (String::empty));
    textButton->setButtonText ("Ciao");
    //textButton->addListener (this);
    setSize (600, 400);
}

MainContentComponent::~MainContentComponent()
{
        //[Destructor_pre]. You can add your own custom destruction code here..
        //[/Destructor_pre]
        
     
        quitButton = nullptr;
        textButton = nullptr;
        //[Destructor]. You can add your own custom destruction code here..
        //[/Destructor]
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
    g.drawText ("Hello Insane World!", getLocalBounds(), Justification::centred, true);
    
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
    
    quitButton->setBounds (getWidth() - 176, getHeight() - 60, 120, 32);
    internalPath1.clear();
    internalPath1.startNewSubPath (136.0f, 80.0f);
    internalPath1.quadraticTo (176.0f, 24.0f, 328.0f, 32.0f);
    internalPath1.quadraticTo (472.0f, 40.0f, 472.0f, 104.0f);
    internalPath1.quadraticTo (472.0f, 192.0f, 232.0f, 176.0f);
    internalPath1.lineTo (184.0f, 216.0f);
    internalPath1.lineTo (200.0f, 168.0f);
    internalPath1.quadraticTo (96.0f, 136.0f, 136.0f, 80.0f);
    internalPath1.closeSubPath();
    
    
    textButton->setBounds (getWidth() - 150, getHeight() - 90, 90, 20);
    internalPath1.clear();
    internalPath1.startNewSubPath (136.0f, 80.0f);
    internalPath1.quadraticTo (176.0f, 24.0f, 328.0f, 32.0f);
    internalPath1.quadraticTo (472.0f, 40.0f, 472.0f, 104.0f);
    internalPath1.quadraticTo (472.0f, 192.0f, 232.0f, 176.0f);
    internalPath1.lineTo (184.0f, 216.0f);
    internalPath1.lineTo (200.0f, 168.0f);
    internalPath1.quadraticTo (96.0f, 136.0f, 136.0f, 80.0f);
    internalPath1.closeSubPath();
}

void MainContentComponent::buttonClicked (Button* buttonThatWasClicked) //NON FUNZIONAAAA
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]
    
    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_quitButton] -- add your button handler code here..
        
        JUCEApplication::quit();
        
        //[/UserButtonCode_quitButton]
    }
    
    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}
