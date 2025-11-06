import bpy

bpy.types.Scene.wuwa_color = bpy.props.FloatVectorProperty(
    name="Color",
    subtype='COLOR',
    size=3,
    min=0.0,
    max=1.0,
    default=(1.0, 1.0, 1.0),
    description="Pick a color for all selected object materials"
)

# does the thing
class WuWaShader(bpy.types.Operator):
    bl_idname = "object.wuwa_internal"
    bl_label = "WuWa Shader Internal"
    bl_description = "Replace anime_shader materials with updated Multiply Color2"
    bl_options = {'REGISTER', 'UNDO'}

    def execute(self, context):
        for mat in bpy.data.materials:
            if not mat.use_nodes:
                continue
            print(mat.name)
            nodes = mat.node_tree.nodes
            for node in nodes:
                if node.type == "GROUP" and node.name == "Group.001":
                    bpy.data.materials[mat.name].node_tree.nodes["Mix"].inputs[7].default_value = (*bpy.context.scene.wuwa_color, 1.0)
        self.report({'INFO'}, "WuWa materials updated")
        return {'FINISHED'}

# displays the thing
class WuWaPanel(bpy.types.Panel):
    bl_idname = "OBJECT_PT_wuwa_shader"
    bl_label = "WuWa Shader"
    bl_space_type = 'VIEW_3D'
    bl_region_type = 'UI'
    bl_category = "WuWa Shader"

    def draw(self, context):
        layout = self.layout
        scene = context.scene

        layout.prop(scene, "wuwa_color", text="Color")

        row = self.layout.row()
        row.operator("object.wuwa_internal", text="Apply")

def register():
    bpy.utils.register_class(WuWaShader)
    bpy.utils.register_class(WuWaPanel)

def unregister():
    bpy.utils.unregister_class(WuWaShader)
    bpy.utils.unregister_class(WuWaPanel)

if __name__ == "__main__":
    register()