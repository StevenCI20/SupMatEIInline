#include "PepiSteppingAction.hh"
#include "G4RunManager.hh"
PepiSteppingAction::PepiSteppingAction(PepiEventAction* eventAction)
{
  fEventAction=eventAction;
}


PepiSteppingAction::~PepiSteppingAction()
{}

void PepiSteppingAction::UserSteppingAction(const G4Step* step)
{
   G4LogicalVolume *volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();
   const PepiDetectorConstruction *detectorConstruction = static_cast<const PepiDetectorConstruction*> (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
   G4LogicalVolume *fScoringVolume = detectorConstruction->GetScoringVolume();
 
   if(volume != fScoringVolume)
       return;




   G4double edep = step->GetTotalEnergyDeposit();
   fEventAction->AddEdep(edep);
}
