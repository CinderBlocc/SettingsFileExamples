#include "SettingsFileExamples.h"
#include "CvarMacros.h"

/*
* 
*   This file can be ignored. The implementations here exist to add some functionality to the plugin 
* 
*/

void SettingsFileExamples::HandleExtraCvars()
{
    EnableRender = std::make_shared<bool>(false);
    cvarManager->registerCvar(CVAR_EXTRA_ENABLERENDER, "0", "Checkbox component", true).bindTo(EnableRender);
    gameWrapper->RegisterDrawable(std::bind(&SettingsFileExamples::Render, this, std::placeholders::_1));

    SameLineCheckbox1 = std::make_shared<bool>(false);
    SameLineCheckbox2 = std::make_shared<bool>(false);
    cvarManager->registerCvar(CVAR_EXTRA_SAMELINECHECKBOX1, "1", "SameLine example checkbox 1", true).bindTo(SameLineCheckbox1);
    cvarManager->registerCvar(CVAR_EXTRA_SAMELINECHECKBOX2, "1", "SameLine example checkbox 2", true).bindTo(SameLineCheckbox2);

    GrayedComponentCheckbox1   = std::make_shared<bool>(false);
    GrayedComponentNesting1    = std::make_shared<bool>(false);
    GrayedComponentNesting2    = std::make_shared<bool>(false);
    GrayedComponentNesting3    = std::make_shared<bool>(false);
    GrayedComponentNesting4    = std::make_shared<bool>(false);
    GrayedComponentInversion1  = std::make_shared<bool>(false);
    cvarManager->registerCvar(CVAR_EXTRA_GRAYEDCHECKBOX, "1", "GrayedComponent example checkbox", true).bindTo(GrayedComponentCheckbox1);
    cvarManager->registerCvar(CVAR_EXTRA_GRAYEDCHECKBOXNESTING1, "1", "GrayedComponent nesting example checkbox 1", true).bindTo(GrayedComponentNesting1);
    cvarManager->registerCvar(CVAR_EXTRA_GRAYEDCHECKBOXNESTING2, "1", "GrayedComponent nesting example checkbox 2", true).bindTo(GrayedComponentNesting2);
    cvarManager->registerCvar(CVAR_EXTRA_GRAYEDCHECKBOXNESTING3, "1", "GrayedComponent nesting example checkbox 3", true).bindTo(GrayedComponentNesting3);
    cvarManager->registerCvar(CVAR_EXTRA_GRAYEDCHECKBOXNESTING4, "1", "GrayedComponent nesting example checkbox 4", true).bindTo(GrayedComponentNesting4);
    cvarManager->registerCvar(CVAR_EXTRA_GRAYEDCHECKBOXINVERSION, "1", "GrayedComponent inversion example checkbox", true).bindTo(GrayedComponentInversion1);

    cvarManager->registerNotifier(NOTIFIER_EXTRA_GRAYEDCOMPONENTBUTTON, [this](std::vector<std::string> params){SetColorExample();}, "Sets a new color to the color picker", PERMISSION_ALL);
}

void SettingsFileExamples::Render(CanvasWrapper canvas)
{
    if(!(*EnableRender))
    {
        return;
    }
    
    Vector2 TopLeft = {50, 50};
    Vector2 BoxSize = {100, 100};
    
    //Box filled with the color specified in the UI
    canvas.SetColor(*Component13_ColorEdit);
    canvas.SetPosition(TopLeft);
    canvas.FillBox(BoxSize);

    //Green outline box
    canvas.SetColor(LinearColor{0,255,0,255});
    canvas.SetPosition(TopLeft);
    canvas.DrawBox(BoxSize);

    canvas.SetPosition(TopLeft + Vector2{BoxSize.X + 5, BoxSize.Y / 2});
    canvas.DrawString("("
                      + std::to_string(Component13_ColorEdit->R) + ", "
                      + std::to_string(Component13_ColorEdit->G) + ", "
                      + std::to_string(Component13_ColorEdit->B) + ", "
                      + std::to_string(Component13_ColorEdit->A) + ")");
}

void SettingsFileExamples::SetColorExample()
{
    cvarManager->executeCommand("openmenu console2");
    cvarManager->log("Changed color in color component example to a nice hot pink");
    cvarManager->getCvar(CVAR_COMPONENT_13).setValue(LinearColor{255,0,255,255});
}