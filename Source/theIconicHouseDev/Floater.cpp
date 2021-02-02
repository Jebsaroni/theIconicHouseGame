// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
	BobPeriod = 7.0f;
	BobDistance = 20.0f;
	RotationSpeed = 20.0f;

	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	if (CubeVisualAsset.Succeeded()) {
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	BaseHeight = GetActorLocation().Z;
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float TotalTime = GetGameTimeSinceCreation();

	FVector NewPos = GetActorLocation();
	NewPos.Z = FMath::Sin(TotalTime * (2 * PI) / BobPeriod) * BobDistance + BaseHeight;

	FRotator NewRot = GetActorRotation();
	NewRot.Yaw += RotationSpeed * DeltaTime;

	SetActorLocationAndRotation(NewPos, NewRot);
}

