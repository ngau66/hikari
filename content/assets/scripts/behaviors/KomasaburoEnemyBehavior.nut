class KomasaburoEnemyBehavior extends EnemyBehavior {
    state = State.IDLE;
    timer = 0.0;
    enteringNewState = false;

    constructor(classConfig = {}) {
        base.constructor(classConfig);
        ::log("KomasaburoEnemyBehavior constructor called.");
    }

    /**
     * Performs host-attachment stuff.
     * @override
     */
    function attachHost(newHost, instanceConfig = {}) {
        base.attachHost(newHost);

        if(host != null) {
            host.weaponId = 3;
        }
    }

    function update(dt) {
        if(host != null) {

            timer += dt;

            switch(state) {
                case State.IDLE:
                    if(enteringNewState) {
                        facePlayer();
                        host.changeAnimation("idle");
                        enteringNewState = false;
                    }

                    if(timer >= 3.0) {
                        timer = 0.0;
                        enteringNewState = true;
                        state = State.SHOOTING;
                    }
                    break;
                case State.SHOOTING:
                    if(enteringNewState) {
                        facePlayer();
                        host.changeAnimation("shooting");
                        host.fireWeapon();
                        enteringNewState = false;
                    }

                    if(timer >= 0.5) {
                        timer = 0.0;
                        enteringNewState = true;
                        state = State.IDLE;
                    }
                    break;
                default:
                    break;
            }
        }

        base.update(dt);
    }

    function handleWorldCollision(side) {

    }
}

::log("KomasaburoEnemyBehavior.nut executed!");