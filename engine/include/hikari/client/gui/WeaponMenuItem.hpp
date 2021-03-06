#ifndef HIKARI_CLIENT_GUI_WEAPONMENUITEM
#define HIKARI_CLIENT_GUI_WEAPONMENUITEM

#include "hikari/client/gui/MenuItem.hpp"
#include <memory>

namespace hikari {
namespace gui {

    class Icon;
    class EnergyGauge;

    class WeaponMenuItem : public MenuItem {
    private:
        static const int DEFAULT_SELECT_BOX_WIDTH;
        static const int DEFAULT_SELECT_BOX_HEIGHT;
        static const int DEFAULT_SELECT_BOX_SPACING;

        int selectBoxWidth;
        int selectBoxHeight;
        int selectBoxSpacing;
        int weaponId;
        std::unique_ptr<EnergyGauge> gauge;
        std::unique_ptr<Icon> selectedIcon;
        std::unique_ptr<Icon> unselectedIcon;

        void initGauge();
    protected:
        virtual void adjustSize();

    public:
        WeaponMenuItem();
        WeaponMenuItem(const std::string & name, int weaponId);
        WeaponMenuItem(const std::string & name, int weaponId, std::unique_ptr<Icon> selected, std::unique_ptr<Icon> unselected);
        virtual ~WeaponMenuItem();

        int getWeaponId() const;

        float getMaximumValue() const;
        float getValue() const;
        void setMaximumValue(float maxValue);
        void setValue(float maxValue);

        // Inherited from Widget
        virtual void draw(gcn::Graphics* graphics);
    };

} // hikari::gui
} // hikari

#endif // HIKARI_CLIENT_GUI_WEAPONMENUITEM
