import bpy  #this must be run in blender! if you dont have blender, bpy must be manually installed

bpy.ops.mesh.primitive_cube_add(size=2, enter_editmode=False, align='WORLD', location=(0, 0, 0), scale=(1, 1, 1))
print("Spawned a cube!")