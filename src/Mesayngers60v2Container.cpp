/*
* ============================================================================
*  Name     : CMesayngers60v2Container from Mesayngers60v2Container.h
*  Part of  : mesayngers60v2
*  Created  : 4/9/2024 by adinandradrs
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Version  :
*  Copyright: 
* ============================================================================
*/

#include <eiklabel.h>
#include <barsread.h>
#include <eikedwin.h>

#include "mesayngers60v2.hrh"
#include "Mesayngers60v2Container.h"

const TInt KNumberOfControls = 4;
const TInt KBufLength = 64;

enum TControls {
    ELabel,
    EToDoLabel,
    EExtLabel,
    EEdwin
};

CMesayngers60v2Container::CMesayngers60v2Container()
    :iLabel(NULL), iToDoLabel(NULL),
     iExtLabel(NULL), iEdwin(NULL) {
}

void CMesayngers60v2Container::ConstructL(const TRect& aRect) {
    CreateWindowL();
    
    iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Hello world Symbian") );
    iLabel->SetExtent( TPoint(10, 10), iLabel->MinimumSize() );

    iToDoLabel = new (ELeave) CEikLabel;
    iToDoLabel->SetContainerWindowL( *this );
    iToDoLabel->SetTextL( _L("Adinandra D. is here") );
    iToDoLabel->SetExtent( TPoint(10, 20), iToDoLabel->MinimumSize() );
    
    iExtLabel = new (ELeave) CEikLabel;
    iExtLabel->SetContainerWindowL( *this );
    iExtLabel->SetTextL( _L("Testing") );
    iExtLabel->SetExtent( TPoint(10, 30), iExtLabel->MinimumSize() );

    TResourceReader reader;
    TBuf<KBufLength> text;
    iCoeEnv->CreateResourceReaderLC(reader, R_MESAYNGERS60V2_VIEW1_EDWIN);
    iEdwin = new (ELeave) CEikEdwin;
    iEdwin->SetContainerWindowL(*this);
    iEdwin->ConstructFromResourceL(reader);
    CleanupStack::PopAndDestroy(); 
    iEdwin->SetExtent(TPoint(10, 60), iEdwin->MinimumSize());

    SetRect(aRect);
    ActivateL();
}

CMesayngers60v2Container::~CMesayngers60v2Container() {
    delete iLabel;
    delete iToDoLabel;
    delete iExtLabel;
    delete iEdwin;
}

void CMesayngers60v2Container::SizeChanged() {
}

TInt CMesayngers60v2Container::CountComponentControls() const {
    return KNumberOfControls;
}

CCoeControl* CMesayngers60v2Container::ComponentControl(TInt aIndex) const {
    switch ( aIndex ) {
        case ELabel:
            return iLabel;
        case EToDoLabel:
            return iToDoLabel;
        case EExtLabel:
            return iExtLabel;
        case EEdwin:
           return iEdwin;
        default:
            return NULL;
    }
}

void CMesayngers60v2Container::Draw(const TRect& aRect) const {
    CWindowGc& gc = SystemGc();
    gc.SetPenStyle( CGraphicsContext::ENullPen );
    gc.SetBrushStyle( CGraphicsContext::ESolidBrush );
    gc.DrawRect( aRect );
}

void CMesayngers60v2Container::HandleControlEventL(CCoeControl*, TCoeEvent) {
}