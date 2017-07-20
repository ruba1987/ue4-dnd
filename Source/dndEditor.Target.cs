using UnrealBuildTool;
using System.Collections.Generic;

public class dndEditorTarget : TargetRules
{
    public dndEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;

        ExtraModuleNames.AddRange(new string[] { "dnd" });
    }
}
