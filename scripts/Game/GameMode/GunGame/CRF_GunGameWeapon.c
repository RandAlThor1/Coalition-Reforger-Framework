[BaseContainerProps(configRoot: true), BaseContainerCustomTitleField("GunGameWeaponSelection")]
class GunGameWeaponSelection
{
	[Attribute("", UIWidgets.ResourceNamePicker, params: "")]
	ResourceName Weapon;
	
	[Attribute("", UIWidgets.ResourceNamePicker, params: "")]
	ResourceName Ammo;
	
	ResourceName getWeapon()
	{
		return Weapon;
	}
	
	string getAmmo()
	{
		return Ammo;
	}
	
}