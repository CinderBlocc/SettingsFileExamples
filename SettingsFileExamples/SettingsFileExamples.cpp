#include "SettingsFileExamples.h"
#include "bakkesmod\wrappers\includes.h"

BAKKESMOD_PLUGIN(SettingsFileExamples, "Examples of all plugins settings", "1.0", PLUGINTYPE_FREEPLAY)


void SettingsFileExamples::onLoad()
{
    //enabled = std::make_shared<bool>(false);
    //cvarManager->registerCvar("SettingsFileExamples_Enabled", "0", "Enable the SettingsFileExamples plugin", true, true, 0, true, 1).bindTo(enabled);

	//cvarManager->registerNotifier("NOTIFIER", [this](std::vector<std::string> params){FUNCTION();}, "DESCRIPTION", PERMISSION_ALL);
	//cvarManager->registerCvar("CVAR", "DEFAULTVALUE", "DESCRIPTION", true, true, MINVAL, true, MAXVAL);//.bindTo(CVARVARIABLE);
	//gameWrapper->HookEvent("FUNCTIONNAME", std::bind(&SettingsFileExamples::FUNCTION, this));
	//gameWrapper->HookEventWithCallerPost<ActorWrapper>("FUNCTIONNAME", std::bind(&SettingsFileExamples::FUNCTION, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
	//gameWrapper->RegisterDrawable(bind(&SettingsFileExamples::Render, this, std::placeholders::_1));

    // < Component 0 > has no storage
    Component1_Checkbox           = std::make_shared<bool>(false);
    Component2_FloatRangeSlider   = std::make_shared<float>(0.f);
    Component3_IntegerRangeSlider = std::make_shared<int>(0);
    Component4_FloatSlider        = std::make_shared<float>(0.f);
    Component5_IntegerSlider      = std::make_shared<int>(0);
    Component6_Combobox           = std::make_shared<std::string>("");
    // < Components 7 to 11 > have no storage
    Component12_Textbox           = std::make_shared<std::string>("");
    Component13_ColorEditNoAlpha  = std::make_shared<LinearColor>(LinearColor{0,0,0,0});
    Component14_ColorEditAlpha    = std::make_shared<LinearColor>(LinearColor{0,0,0,0});

    cvarManager->registerNotifier("Settings_Component0", [this](std::vector<std::string> params){OnComponent0Action();}, "Opens console", PERMISSION_ALL);
    CVarWrapper Cvar_Component1 = cvarManager->registerCvar("Settings_Component1", "1", "Affects Component10 greyed box", true);
    
    //Bind cvar to variable
    Cvar_Component1.bindTo(Component1_Checkbox);

    Cvar_Component1.addOnValueChanged(std::bind(&OnComponent1Action, this));


}
void SettingsFileExamples::onUnload() {}



void SettingsFileExamples::OnComponent0Action()
{
    /*
        Button has been pressed.
        Execute the function tied to the notifier.
    */

    //Opens console to show the following printed information
    cvarManager->executeCommand("openmenu console2");
    
    float X = 10;
    float Y = 5;
    float Z = X * Y;

    cvarManager->log("The result of " + std::to_string(X) + " times " + std::to_string(Y) + " is: " + std::to_string(Z));
}

void SettingsFileExamples::OnComponent1Action()
{
    /*
        Checkbox has either been checked or unchecked.

    */
}

void SettingsFileExamples::OnComponent2Action()
{

}

void SettingsFileExamples::OnComponent3Action()
{

}

void SettingsFileExamples::OnComponent4Action()
{

}

void SettingsFileExamples::OnComponent5Action()
{

}

void SettingsFileExamples::OnComponent6Action()
{

}

void SettingsFileExamples::OnComponent7Action()
{

}

void SettingsFileExamples::OnComponent8Action()
{

}

void SettingsFileExamples::OnComponent9Action()
{

}

void SettingsFileExamples::OnComponent10Action()
{

}

void SettingsFileExamples::OnComponent11Action()
{

}

void SettingsFileExamples::OnComponent12Action()
{

}

void SettingsFileExamples::OnComponent13Action()
{

}

void SettingsFileExamples::OnComponent14Action()
{

}

