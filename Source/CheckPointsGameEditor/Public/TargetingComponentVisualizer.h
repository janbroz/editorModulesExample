#pragma once

#include "ComponentVisualizer.h"
#include "Cannon/TargetingComponent.h"

class FTargetingComponentVisualizer : public FComponentVisualizer
{
public:
	FTargetingComponentVisualizer();
	virtual ~FTargetingComponentVisualizer() {}

	// Begin FComponentVisualizer interface
	virtual void OnRegister() override;
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
	virtual bool VisProxyHandleClick(FEditorViewportClient* InViewportClient, HComponentVisProxy* VisProxy, const FViewportClick& Click) override;
	virtual void EndEditing() override;
	virtual bool GetWidgetLocation(const FEditorViewportClient* ViewportClient, FVector& OutLocation) const override;
	virtual bool GetCustomInputCoordinateSystem(const FEditorViewportClient* ViewportClient, FMatrix& OutMatrix) const override;
	virtual bool HandleInputDelta(FEditorViewportClient* ViewportClient, FViewport* Viewport, FVector& DeltaTranslate, FRotator& DeltaRotate, FVector& DeltaScale) override;
	virtual bool HandleInputKey(FEditorViewportClient* ViewportClient, FViewport* Viewport, FKey Key, EInputEvent Event) override;
	virtual TSharedPtr<SWidget> GenerateContextMenu() const override;
	// New available methods
	virtual void DrawVisualizationHUD(const UActorComponent* Component, const FViewport* Viewport, const FSceneView* View, FCanvas* Canvas);
	virtual bool IsVisualizingArchetype();
	// End FComponentVisualizer interface

	/** Get the target component we are currently editing */
	UTargetingComponent* GetEditedTargetingComponent() const;

private:
    /**Index of target in selected component*/
    int32 CurrentlySelectedTarget;

	/**Output log commands*/
	TSharedPtr<FUICommandList> TargetingComponentVisualizerActions;
	
	UTargetingComponent* CurrentTargetComponent;
};

struct HTargetingVisProxy : public HComponentVisProxy
{
	DECLARE_HIT_PROXY();

	HTargetingVisProxy(const UActorComponent* InComponent)
		: HComponentVisProxy(InComponent, HPP_Wireframe)
	{}
};

/**Proxy for target*/
struct HTargetProxy : public HTargetingVisProxy
{
	DECLARE_HIT_PROXY();

	HTargetProxy(const UActorComponent* InComponent, int32 InTargetIndex)
		: HTargetingVisProxy(InComponent)
		, TargetIndex(InTargetIndex)
	{}

	int32 TargetIndex;
};