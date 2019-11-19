#include "TargetingComponentVisualizer.h"
#include "Cannon/TargetingComponent.h"

IMPLEMENT_HIT_PROXY(HTargetingVisProxy, HComponentVisProxy)
IMPLEMENT_HIT_PROXY(HTargetProxy, HTargetingVisProxy )

FTargetingComponentVisualizer::FTargetingComponentVisualizer()
{
}

void FTargetingComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	//cast the component into the expected component type
	if(const UTargetingComponent* TargetingComponent = Cast<const UTargetingComponent>(Component))
	{
		//get colors for selected and unselected targets
		//This is an editor only uproperty of our targeting component, that way we can change the colors if we can't see them against the background
		CurrentTargetComponent = const_cast<UTargetingComponent*>(TargetingComponent);
		const FLinearColor SelectedColor = TargetingComponent->EditorSelectedColor;
		const FLinearColor UnselectedColor = TargetingComponent->EditorUnselectedColor;

		
		const FVector Location = TargetingComponent->GetOwner()->GetActorLocation();

		//Iterate over each target drawing a line and dot
		for(int i = 0; i < TargetingComponent->Targets.Num(); i++)
		{
			FLinearColor Color = (i == CurrentlySelectedTarget) ? SelectedColor : UnselectedColor;

			//Set our hit proxy
			PDI->SetHitProxy(new HTargetProxy(Component, i));
			PDI->DrawLine(Location, TargetingComponent->Targets[i], Color, SDPG_Foreground);
			PDI->DrawLine(TargetingComponent->Targets[i], TargetingComponent->Targets[i] + FVector(0, 0, 200.f), Color, SDPG_Foreground);
			PDI->DrawPoint(TargetingComponent->Targets[i], Color, 20.f, SDPG_Foreground);
			PDI->SetHitProxy(NULL);
		}
	}
}

bool FTargetingComponentVisualizer::VisProxyHandleClick(FEditorViewportClient* InViewportClient, HComponentVisProxy* VisProxy, const FViewportClick& Click)
{
	bool bEditing = false;

	if (VisProxy && VisProxy->Component != nullptr)																		
	{
		bEditing = true;

		if(VisProxy->IsA(HTargetProxy::StaticGetType()))
		{
			HTargetProxy* Proxy = (HTargetProxy*) VisProxy;

			CurrentlySelectedTarget = Proxy->TargetIndex;
		}
	}
	else
	{
		CurrentlySelectedTarget = INDEX_NONE;
	}

	return bEditing;
}

bool FTargetingComponentVisualizer::GetWidgetLocation(const FEditorViewportClient* ViewportClient, FVector& OutLocaction) const
{
	if (GetEditedTargetingComponent() != nullptr && CurrentlySelectedTarget != INDEX_NONE)
	{
		OutLocaction = GetEditedTargetingComponent()->Targets[CurrentlySelectedTarget];
		
		return true;
	}

	return false;
}

bool FTargetingComponentVisualizer::HandleInputDelta(FEditorViewportClient* ViewportClient,
	FViewport* Viewport, FVector& DeltaTranslate, FRotator& DeltaRotate, FVector& DeltaScale)
{
	bool bHandled = false;

	if (GetEditedTargetingComponent() != nullptr && CurrentlySelectedTarget != INDEX_NONE)
	{
		GetEditedTargetingComponent()->Targets[CurrentlySelectedTarget] += DeltaTranslate;
		bHandled = true;
	}

	return bHandled;
}

bool FTargetingComponentVisualizer::HandleInputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event)
{
	bool bHandled = false;

	if (Key == EKeys::Delete)
	{
		if(GetEditedTargetingComponent() != nullptr && CurrentlySelectedTarget != INDEX_NONE)
		{
			GetEditedTargetingComponent()->DeleteTarget(CurrentlySelectedTarget);
			bHandled = true;
		}
	}
	return bHandled;
}

void FTargetingComponentVisualizer::OnRegister()
{
	
}

void FTargetingComponentVisualizer::EndEditing()
{
}

bool FTargetingComponentVisualizer::GetCustomInputCoordinateSystem(const FEditorViewportClient* ViewportClient, FMatrix& OutMatrix) const
{
	return true;
}

TSharedPtr<SWidget> FTargetingComponentVisualizer::GenerateContextMenu() const
{
	return nullptr;
}

void FTargetingComponentVisualizer::DrawVisualizationHUD(const UActorComponent* Component, const FViewport* Viewport, const FSceneView* View, FCanvas* Canvas)
{
	
}

bool FTargetingComponentVisualizer::IsVisualizingArchetype()
{
	return true;
}

UTargetingComponent* FTargetingComponentVisualizer::GetEditedTargetingComponent() const
{
	return CurrentTargetComponent;
}
