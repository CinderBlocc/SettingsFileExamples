#pragma once
#pragma comment(lib, "pluginsdk.lib")
#include "bakkesmod/plugin/bakkesmodplugin.h"

class SettingsFileExamples : public BakkesMod::Plugin::BakkesModPlugin
{
private:
    //                           Component0_Button;                // Tied to a notifier/command, not a cvar
    std::shared_ptr<bool>        Component1_Checkbox;              // Will set cvar to true or false
    std::shared_ptr<float>       Component2_FloatRangeSlider;      // Range slider allowing the user to select a range (float)
    std::shared_ptr<int>         Component3_IntegerRangeSlider;    // Range slider allowing the user to select a range (integer)
    std::shared_ptr<float>       Component4_FloatSlider;           // Slider allowing the user to select one value (float)
    std::shared_ptr<int>         Component5_IntegerSlider;         // Slider allowing the user to select one value (integer)
    std::shared_ptr<std::string> Component6_Combobox;              // Dropdown menu. Formatting: key1@val1&key2@val2, will display "key1" and "key2" to the user, and set cvar to either "val1" or "val2"
    //                           Component7_SameLine;              // Puts the previous and the next UI components on the same line
    //                           Component8_Separator;             // Draws a horizontal line across the whole plugin window
    //                           Component9_Label;                 // Draws text. Can display cvar values (9|cl_goalreplay_pov value is $cl_goalreplay_pov$)
    //                           Component10_GreyedComponentStart; // Will disable all components below if the evaluated cvar is false until grayed component end is found
    //                           Component11_GreyedComponentEnd;   // Ends the earlier declared grayed component section
    std::shared_ptr<std::string> Component12_Textbox;              // Cvar value = textbox value. Note: this will automatically be applied as soon as a single character is added/removed/changed.
    std::shared_ptr<LinearColor> Component13_ColorEditNoAlpha;     // Color selector. Doesn't include alpha editing
    std::shared_ptr<LinearColor> Component14_ColorEditAlpha;       // Color selector. Includes alpha editing

public:
	void onLoad() override;
	void onUnload() override;

    // For more information about each component, go to the implementation of the following functions
    void OnComponent0Action();
    void OnComponent1Action();
    void OnComponent2Action();
    void OnComponent3Action();
    void OnComponent4Action();
    void OnComponent5Action();
    void OnComponent6Action();
    void OnComponent7Action();
    void OnComponent8Action();
    void OnComponent9Action();
    void OnComponent10Action();
    void OnComponent11Action();
    void OnComponent12Action();
    void OnComponent13Action();
    void OnComponent14Action();

};
