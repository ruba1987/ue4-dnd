using UnrealBuildTool;
using System.Collections.Generic;

public class DndEditorTarget : TargetRules
{
    public DndEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;

        ExtraModuleNames.AddRange(new string[] { "Dnd" });
    }
}
