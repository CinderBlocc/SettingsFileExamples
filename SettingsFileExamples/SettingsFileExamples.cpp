#include "SettingsFileExamples.h"
#include "bakkesmod\wrappers\includes.h"

BAKKESMOD_PLUGIN(SettingsFileExamples, "Examples of all plugins settings", "1.0", PLUGINTYPE_FREEPLAY)


void SettingsFileExamples::onLoad()
{
    // Finish setting up the cvar storage here

    // Component 0 has no storage
    Component1_Checkbox           = std::make_shared<bool>(false);
    Component2_FloatRangeSlider   = std::make_shared<float>(0.f);
    Component3_IntegerRangeSlider = std::make_shared<int>(0);
    Component4_FloatSlider        = std::make_shared<float>(0.f);
    Component5_IntegerSlider      = std::make_shared<int>(0);
    Component6_Combobox           = std::make_shared<std::string>("");
    // Components 7 to 11 have no storage
    Component12_Textbox           = std::make_shared<std::string>("");
    //Component13_ColorEdit         = std::make_shared<LinearColor>(LinearColor{0,0,0,0});


    //Registers a notifier / command. Mostly used with component 0 (button)
    cvarManager->registerNotifier("Settings_Component0", [this](std::vector<std::string> params){Component0();}, "Opens console", PERMISSION_ALL);
    
    //Registers a cvar (console variable)
    CVarWrapper Cvar_Component1  = cvarManager->registerCvar("Settings_Component1",  "1",            "Checkbox component",       true);
    CVarWrapper Cvar_Component2  = cvarManager->registerCvar("Settings_Component2",  "(0.33, 0.66)", "Float range component",    true, true, 0, true, 1);
    CVarWrapper Cvar_Component3  = cvarManager->registerCvar("Settings_Component3",  "(33, 66)",     "Integer range component",  true, true, 0, true, 100);
    CVarWrapper Cvar_Component4  = cvarManager->registerCvar("Settings_Component4",  "0.5",          "Float slider component",   true, true, 0, true, 1);
    CVarWrapper Cvar_Component5  = cvarManager->registerCvar("Settings_Component5",  "50",           "Integer slider component", true, true, 0, true, 100);
    CVarWrapper Cvar_Component6  = cvarManager->registerCvar("Settings_Component6",  "Cat",          "Combobox component",       true);
    CVarWrapper Cvar_Component12 = cvarManager->registerCvar("Settings_Component12", "InputText",    "Textbox component",        true);
    //CVarWrapper Cvar_Component13 = cvarManager->registerCvar("Settings_Component13", "#FFFFFF",      "Color edit component",     true);
    
    //Bind cvar to variable (optional). You can still access a bound or unbound cvar via `cvarManager->getCvar("Cvar_Name").getTYPEValue()`
    //NOTE: You cannot set a cvar value through its bind. You have to set its value via  `cvarManager->getCvar("Cvar_Name").setValue(value)`
    Cvar_Component1.bindTo(Component1_Checkbox);
    Cvar_Component2.bindTo(Component2_FloatRangeSlider);
    Cvar_Component3.bindTo(Component3_IntegerRangeSlider);
    Cvar_Component4.bindTo(Component4_FloatSlider);
    Cvar_Component5.bindTo(Component5_IntegerSlider);
    Cvar_Component6.bindTo(Component6_Combobox);
    Cvar_Component12.bindTo(Component12_Textbox);
    //Cvar_Component13.bindTo(Component13_ColorEdit);

    //Run a function if the value has changed (optional)
    Cvar_Component1.addOnValueChanged(  std::bind(&SettingsFileExamples::Component1,  this));
    Cvar_Component2.addOnValueChanged(  std::bind(&SettingsFileExamples::Component2,  this));
    Cvar_Component3.addOnValueChanged(  std::bind(&SettingsFileExamples::Component3,  this));
    Cvar_Component4.addOnValueChanged(  std::bind(&SettingsFileExamples::Component4,  this));
    Cvar_Component5.addOnValueChanged(  std::bind(&SettingsFileExamples::Component5,  this));
    Cvar_Component6.addOnValueChanged(  std::bind(&SettingsFileExamples::Component6,  this));
    Cvar_Component12.addOnValueChanged( std::bind(&SettingsFileExamples::Component12, this));
    //Cvar_Component13.addOnValueChanged( std::bind(&SettingsFileExamples::Component13, this));


    //Extra cvars to make the plugin functional. A couple helpful notes in here, but other than that this can be ignored.
    HandleExtraCvars();
}
void SettingsFileExamples::onUnload() {}
void SettingsFileExamples::HandleExtraCvars()
{
    //Enable the render function to display the color edit
    //Note that if you're only binding a variable and not also adding onValueChanged (or vice versa), you can just tack the bind/valuechanged to the end of the register call
    EnableRender = std::make_shared<bool>(false);
    cvarManager->registerCvar("Settings_Extra_EnableRender", "0", "Checkbox component", true).bindTo(EnableRender);

    SameLineCheckbox1 = std::make_shared<bool>(false);
    SameLineCheckbox2 = std::make_shared<bool>(false);
    cvarManager->registerCvar("Settings_Extra_SameLineCheckbox1", "1", "SameLine example checkbox 1", true).bindTo(SameLineCheckbox1);
    cvarManager->registerCvar("Settings_Extra_SameLineCheckbox2", "1", "SameLine example checkbox 2", true).bindTo(SameLineCheckbox2);

    GreyedComponentCheckbox1   = std::make_shared<bool>(false);
    GreyedComponentNesting1    = std::make_shared<bool>(false);
    GreyedComponentNesting2    = std::make_shared<bool>(false);
    GreyedComponentNesting3    = std::make_shared<bool>(false);
    GreyedComponentNesting4    = std::make_shared<bool>(false);
    GreyedComponentInversion1  = std::make_shared<bool>(false);
    cvarManager->registerCvar("Settings_Extra_GreyedCheckbox1", "1", "GreyedComponent example checkbox 1", true).bindTo(GreyedComponentCheckbox1);
    cvarManager->registerCvar("Settings_Extra_GreyedCheckboxNesting1", "1", "GreyedComponent nesting example checkbox 1", true).bindTo(GreyedComponentNesting1);
    cvarManager->registerCvar("Settings_Extra_GreyedCheckboxNesting2", "1", "GreyedComponent nesting example checkbox 2", true).bindTo(GreyedComponentNesting2);
    cvarManager->registerCvar("Settings_Extra_GreyedCheckboxNesting3", "1", "GreyedComponent nesting example checkbox 3", true).bindTo(GreyedComponentNesting3);
    cvarManager->registerCvar("Settings_Extra_GreyedCheckboxNesting4", "1", "GreyedComponent nesting example checkbox 4", true).bindTo(GreyedComponentNesting4);
    cvarManager->registerCvar("Settings_Extra_GreyedCheckboxInversion1", "1", "GreyedComponent inversion example checkbox 1", true).bindTo(GreyedComponentInversion1);
}

void SettingsFileExamples::Render(CanvasWrapper canvas)
{
    // This function is here to display the color edit component in action
    // Render is called every game render frame

    //if(!(*EnableRender))
    //{
    //    return;
    //}
    //
    //Vector2 TopLeft = {50, 50};
    //Vector2 BoxSize = {100, 100};
    //
    //canvas.SetColor(*Component13_ColorEdit);
    //canvas.SetPosition(TopLeft);
    //canvas.FillBox(BoxSize);
}




// IMPORTANT NOTE: Labels cannot be identical. If you need to have to components with the same text, append them with a tag. Tags begin with ##

// Example 1: "0|Start##defender|defender_start" and "0|Start##other|other_start"

// Example 2: "9|This is text##tag1" and "9|This is text##tag2"




// COMPONENT 0: Button //
/*
    FORMAT:
        0|Label|Command

    DESCRIPTION:
        A button that is tied to a notifier (console command).

    UI ACTION:
        Button has been pressed.
        Execute the function tied to the notifier (this function).

    CONSOLE COMMAND:
        <NotifierName>
*/
void SettingsFileExamples::Component0()
{
    //Opens console to show the following printed information
    cvarManager->executeCommand("openmenu console2");
    
    int X = 10;
    int Y = 5;
    int Z = X * Y;

    cvarManager->log("The result of " + std::to_string(X) + " times " + std::to_string(Y) + " is: " + std::to_string(Z));
}


// COMPONENT 1: Checkbox //
/*
    FORMAT:
        1|Label|CvarName

    DESCRIPTION:
        A checkbox that is tied to a boolean cvar.

    UI ACTION:
        Checkbox has either been checked or unchecked.

    CONSOLE COMMAND:
        <CvarName> <boolean value (0|1, not true|false)>
*/
void SettingsFileExamples::Component1()
{
    if(*Component1_Checkbox)
    {
        cvarManager->log("Component1_Checkbox has been checked");
    }
    else
    {
        cvarManager->log("Component1_Checkbox has been unchecked");
    }
}


// COMPONENT 2: Float Range Slider //
/*
    FORMAT:
        2|Label|CvarName|MinVal|MaxVal

    DESCRIPTION:
        A slider with two bars in it that define a range of float values.
        Getting the value from the bound variable will always be the same unless you call getFloatValue().
        Calling getFloatValue() will set a new random value within the specified range to the variable.

    UI ACTION:
        The range has been updated.

    CONSOLE COMMANDS:
        <CvarName> (<float value>, <float value>)
        <CvarName> <float value>
*/
void SettingsFileExamples::Component2()
{
    // Result from getFloatValue() could optionally be stored in a separate float variable
    /*float newRandValueInRange = */cvarManager->getCvar("Settings_Component2").getFloatValue();
    cvarManager->log("New float range random value: " + std::to_string(*Component2_FloatRangeSlider));
}


// COMPONENT 3: Integer Range Slider //
/*
    FORMAT:
        3|Label|CvarName|MinVal|MaxVal

    DESCRIPTION:
        A slider with two bars in it that define a range of integer values.
        Getting the value from the bound variable will always be the same unless you call getIntValue().
        Calling getIntValue() will set a new random value within the specified range to the variable.

    UI ACTION:
        The range has been updated.

    CONSOLE COMMANDS:
        <CvarName> (<integer value>, <integer value>)
        <CvarName> <integer value>
*/
void SettingsFileExamples::Component3()
{
    // Result from getIntValue() could optionally be stored in a separate float variable
    /*int newRandValueInRange = */cvarManager->getCvar("Settings_Component3").getIntValue();
    cvarManager->log("New integer range random value: " + std::to_string(*Component3_IntegerRangeSlider));
}


// COMPONENT 4: Float Slider //
/*
    FORMAT:
        4|Label|CvarName|MinVal|MaxVal

    DESCRIPTION:
        A slider with one bar in it that specifies a float value.

    UI ACTION:
        The slider has been updated.

    CONSOLE COMMAND:
        <CvarName> <float value>
*/
void SettingsFileExamples::Component4()
{
    cvarManager->log("New value in float slider: " + std::to_string(*Component4_FloatSlider));
}


// COMPONENT 5: Integer Slider //
/*
    FORMAT:
        5|Label|CvarName|MinVal|MaxVal

    DESCRIPTION:
        A slider with one bar in it that specifies an integer value.

    UI ACTION:
        The slider has been updated.

    CONSOLE COMMAND:
        <CvarName> <integer value>
*/
void SettingsFileExamples::Component5()
{
    cvarManager->log("New value in integer slider: " + std::to_string(*Component5_IntegerSlider));
}


// COMPONENT 6: Combobox //
/*
    FORMAT:
        6|Label|CvarName|Options

    DESCRIPTION:
        Dropdown menu displaying a list of string options.
        "Options" formatting is as follows:
            key1@value1&key2@value2
        This will display "key1" and "key2" in the dropdown list,
        and will set the cvar value to the respective "value1" or "value2" when clicked.
        
    UI ACTION:
        A selection has been made in the dropdown menu.

    CONSOLE COMMAND:
        <CvarName> <string value>
*/
void SettingsFileExamples::Component6()
{
    cvarManager->log("New value selected in combobox: " + *Component6_Combobox);
}


// COMPONENT 7: Same Line //
/*
    FORMAT:
        7|

    DESCRIPTION:
        This component puts the previous component and the next component on the same line.

    UI ACTION:
        None.

    CONSOLE COMMAND:
        None.
*/
void SettingsFileExamples::Component7()
{
    //No addOnValueChanged hook available
}


// COMPONENT 8: Separator //
/*
    FORMAT:
        8|

    DESCRIPTION:
        This component puts a horizontal line across the plugin window.

    UI ACTION:
        None.

    CONSOLE COMMAND:
        None.
*/
void SettingsFileExamples::Component8()
{
    //No addOnValueChanged hook available
}


// COMPONENT 9: Label //
/*
    FORMAT:
        9|Label

    DESCRIPTION:
        This component prints whatever text follows "9|".
        LIMITED TO 1024 CHARACTERS!
        Cvar values (i.e. dynamic text) can be included between two dollar signs ($). For example:
            9|cl_goalreplay_pov value is $cl_goalreplay_pov$.
        will display in the UI as:
            cl_goalreplay_pov value is 1.

    UI ACTION:
        None.

    CONSOLE COMMAND:
        None.
*/
void SettingsFileExamples::Component9()
{
    //No addOnValueChanged hook available
}


// COMPONENT 10: Greyed Component Start //
/*
    FORMAT:
        10|CvarName

    DESCRIPTION:
        All components between 10| and 11| will be faded and inaccessible.
        "Cvar" must be evaluatable to "true" or "false".

    UI ACTION:
        None.

    CONSOLE COMMAND:
        None.
*/
void SettingsFileExamples::Component10()
{
    //No addOnValueChanged hook available
}


// COMPONENT 11: Greyed Component End //
/*
    FORMAT:
        11|

    DESCRIPTION:
        Closes off the greyed out section started by Component 10

    UI ACTION:
        None.

    CONSOLE COMMAND:
        None.
*/
void SettingsFileExamples::Component11()
{
    //No addOnValueChanged hook available
}


// COMPONENT 12: Textbox //
/*
    FORMAT:
        12|Label|CvarName

    DESCRIPTION:
        Whatever text is in the textbox will be stored in the supplied Cvar.
        NOTE: Text will automatically be applied to the cvar as soon as a single character is added/removed/changed

    UI ACTION:
        Text has been typed into or removed from the box.

    CONSOLE COMMAND:
        <CvarName> <string value>
*/
void SettingsFileExamples::Component12()
{
    cvarManager->log("New value typed in textbox: " + *Component12_Textbox);
}


// COMPONENT 13: Color Edit - CURRENTLY NOT AVAILABLE. COMING SOON tm
/*
    FORMAT:
        13|Label|CvarName

    DESCRIPTION:
        Color selection box, RGBA.

    UI ACTION:
        Color has been changed in the picker.

    CONSOLE COMMANDS:
        <CvarName> (<R float value 0-255> <G float value 0-255> <B float value 0-255> <A float value 0-255>)
        <CvarName> <6 character hex code starting with #>
*/
void SettingsFileExamples::Component13()
{
    // See Render function at the top of this file for colors in action
}
