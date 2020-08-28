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
    //std::shared_ptr<LinearColor> Component13_ColorEdit;            // Color selector


    //Extra cvars to make this plugin functional
    std::shared_ptr<bool> EnableRender;
    std::shared_ptr<bool> SameLineCheckbox1;
    std::shared_ptr<bool> SameLineCheckbox2;
    std::shared_ptr<bool> GreyedComponentCheckbox1;
    std::shared_ptr<bool> GreyedComponentNesting1;
    std::shared_ptr<bool> GreyedComponentNesting2;
    std::shared_ptr<bool> GreyedComponentNesting3;
    std::shared_ptr<bool> GreyedComponentNesting4;
    std::shared_ptr<bool> GreyedComponentInversion1;

public:
	void onLoad() override;
	void onUnload() override;
    void Render(CanvasWrapper canvas);
    void HandleExtraCvars();

    // For more information about each component, go to the implementation of the following functions
    void Component0();
    void Component1();
    void Component2();
    void Component3();
    void Component4();
    void Component5();
    void Component6();
    void Component7();
    void Component8();
    void Component9();
    void Component10();
    void Component11();
    void Component12();
    void Component13();
};
