#include "CheckPointsEditorModule.h"
#include "TargetingComponentVisualizer.h"

IMPLEMENT_GAME_MODULE(FCheckPointsEditorModule, CheckPointsGameEditor);

#define LOCTEXT_NAMESPACE "FCheckPointsEditorModule"

void FCheckPointsEditorModule::StartupModule()
{
	UE_LOG(LogTemp, Warning, TEXT("StartupModule() called"));
	
	if (GUnrealEd != NULL)
	{
		TSharedPtr<FComponentVisualizer> Visualizer = MakeShareable(new FTargetingComponentVisualizer());
		
		if (Visualizer.IsValid())
		{
				GUnrealEd->RegisterComponentVisualizer(UTargetingComponent::StaticClass()->GetFName(), Visualizer);
			Visualizer->OnRegister();
		}

	}
}

void FCheckPointsEditorModule::ShutdownModule()
{
	UE_LOG(LogTemp, Warning, TEXT("ShutdownModule() called"));
	if (GUnrealEd != NULL)
	{
		GUnrealEd->UnregisterComponentVisualizer(UTargetingComponent::StaticClass()->GetFName());
	}
}

#undef LOCTEXT_NAMESPACE