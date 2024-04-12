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

#include "Mesayngers60v2Container.h"
#include <eiklabel.h>
#include <barsread.h>
#include <eikedwin.h> 

void CMesayngers60v2Container::ConstructL(const TRect& aRect) {
    CreateWindowL();
    
    iLabel = new (ELeave) CEikLabel;
    iLabel->SetContainerWindowL( *this );
    iLabel->SetTextL( _L("Hello world Symbian") );

    iToDoLabel = new (ELeave) CEikLabel;
    iToDoLabel->SetContainerWindowL( *this );
    iToDoLabel->SetTextL( _L("Adinandra D. is here") );

    //TResourceReader reader;
    
    iExtLabel = new (ELeave) CEikLabel;
    iExtLabel->SetContainerWindowL( *this );
    iExtLabel->SetTextL( _L("Testing") );

    SetRect(aRect);
    ActivateL();
}

CMesayngers60v2Container::~CMesayngers60v2Container() {
    delete iLabel;
    delete iToDoLabel;
    delete iExtLabel;
}

void CMesayngers60v2Container::SizeChanged() {
    iLabel->SetExtent( TPoint(10, 10), iLabel->MinimumSize() );
    iToDoLabel->SetExtent( TPoint(10, 20), iToDoLabel->MinimumSize() );
    iExtLabel->SetExtent( TPoint(10, 30), iExtLabel->MinimumSize() );
}

TInt CMesayngers60v2Container::CountComponentControls() const {
    return 3;
}

CCoeControl* CMesayngers60v2Container::ComponentControl(TInt aIndex) const {
    switch ( aIndex ) {
        case 0:
            return iLabel;
        case 1:
            return iToDoLabel;
        case 2:
            return iExtLabel;
        default:
            return NULL;
    }
}

void CMesayngers60v2Container::Draw(const TRect& aRect) const {
    CWindowGc& gc = SystemGc();
    gc.SetPenStyle( CGraphicsContext::ENullPen );
    gc.SetBrushColor( KRgbGray );
    gc.SetBrushStyle( CGraphicsContext::ESolidBrush );
    gc.DrawRect( aRect );
}

void CMesayngers60v2Container::HandleControlEventL(CCoeControl*, TCoeEvent) {
    
}