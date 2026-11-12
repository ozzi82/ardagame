using UnrealBuildTool;
using System.Collections.Generic;
public class RealmsUnboundTarget : TargetRules
{
    public RealmsUnboundTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        ExtraModuleNames.Add("RealmsUnbound");
    }
}
