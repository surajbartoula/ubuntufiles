# SPRITEKIT TUTORIALS ![alt text](<spritekit (1).png>)

**For creating Player**
1. Create node by initailizing.
2. Set the AnchorPoint for inial placement of the x and y axis.
3. Set the position with respect to anchorpoint.
4. add the node on the screen with self.addchild().

**Adding texture and action to player.**
1. Use SKTextureAtlas to select the folder.
2. Use the variable from SKTextureAtlas.textureNamed("action_name").
3. Use SKAction to animate the texture by calling SKAction.animate(with: , timePerFrame: ).
4. Then use SKAction.repeatForever(the_previous_variable).

**Types of Core Graphics**
1. CGPoint -> Point with x & y coordinates. CGPoint(x: 10, y: 10)
2. CGSize  -> Structure with width & height. CGPoint(widht: 50, height: 30)
3. CGRect  -> With width, height & origin. CGRect(origin: CGPoint(x: 0, y:2), size: CGSize(width:10, height:20))

**IMPULSE & FORCE**
Impulse -> one time force 👊 .
Force   -> constant force on the body to propel like rocket or cars 🚀.

SpriteKit Cycle
1. Update
2. EvaluateActions
3. didEvaluateActions
4. simulatesPhysics
5. didSimulatePhysics
6. applyConstrains
7. didApplyConstraints
8. didFinishUpdate
9. SKView render the scene