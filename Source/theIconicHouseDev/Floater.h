// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Floater.generated.h"

UCLASS()
class THEICONICHOUSEDEV_API AFloater : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floater")
	// Number of seconds for one cycle between [-BobDistance, BobDistance].
	float BobPeriod;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floater")
	// How far above and below the starting height to move.
	float BobDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Floater")
	// Speed in degrees per second.
	float RotationSpeed;

private:
	float BaseHeight;
	
public:	
	// Sets default values for this actor's properties
	AFloater();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
