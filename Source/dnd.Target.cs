using UnrealBuildTool;
using System.Collections.Generic;

public class DndTarget : TargetRules
{
    public DndTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;

        ExtraModuleNames.AddRange(new string[] { "Dnd" });
    }
}
