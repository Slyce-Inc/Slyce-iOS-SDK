rm -f './Resources/xcassets_color_loading.txt'
rm -f './Resources/xcassets_grey_loading.txt'

for file in './SlyceSDKAssets.xcassets/Loader/Color/*.imageset'; do
filename=$(basename $file | cut -f 1 -d '.')
echo -e "$filename" > './Resources/xcassets_color_loading.txt'
done

for file in './SlyceSDKAssets.xcassets/Loader/Grey/*.imageset'; do
filename=$(basename $file | cut -f 1 -d '.')
echo -e "$filename" > './Resources/xcassets_greyscale_loading.txt'
done
