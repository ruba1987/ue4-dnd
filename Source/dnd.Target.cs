using UnrealBuildTool;
using System.Collections.Generic;

public class dndTarget : TargetRules
{
    public dndTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;

        ExtraModuleNames.AddRange(new string[] { "dnd" });
    }
}
